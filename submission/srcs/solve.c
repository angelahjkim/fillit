/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:26:50 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 18:49:07 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** We know that each shape is composed of 4 pieces. To find the smallest
** possible grid that could fit our shape(s) we decided to multiply the number
** of shapes by 4 and then take the integer closest to the square root of the
** result to be the grid length. If the shapes cannot be placed into the grid,
** we increase the size until we get a large enough grid that can hold all the
** shapes.
*/

t_grid	*solve(t_list *list)
{
	t_grid	*grid;
	int		size;

	size = top_sqrt(ft_lstsize(list) * 4);
	grid = create_grid(size);
	while (!(solve_grid(grid, list)))
	{
		size++;
		free_grid(grid);
		grid = create_grid(size);
	}
	return (grid);
}

int		top_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

/*
** This function recursively places the tetrimino shapes in the order they
** are stored in our list onto the grid. If a shape cannot be placed, it will
** be removed (replaced with '.') from the grid and attempted to be placed in
** the next point on the grid. As each shape is successfully placed, the list
** will eventually reach its end (list = NULL) and return 1. If every point
** on the grid is tried and not all shapes have been placed, the grid is too
** small and the function will return 0.
*/

int		solve_grid(t_grid *grid, t_list *list)
{
	t_tetri		*tetri;
	int			y;
	int			x;

	if (list == NULL)
		return (1);
	tetri = (t_tetri *)list->content;
	y = 0;
	while (y < grid->size - tetri->height + 1)
	{
		x = 0;
		while (x < grid->size - tetri->width + 1)
		{
			if (placep_grid(tetri, grid, x, y))
			{
				if (solve_grid(grid, list->next))
					return (1);
				else
					fplace_grid(tetri, grid, create_xy(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** This function takes a tetri struct, grid, and x-y coordinates. Using the
** 2D shape array of the tetrimino shape as well as its width and height to
** check if the shape can be placed onto the grid, starting from the given
** x-y coordinates, in its entirety. If a piece of the shape overlaps with
** a non-empty spot on the grid, the shape cannot be placed, and the function
** returns 0.
*/

int		placep_grid(t_tetri *tetri, t_grid *grid, int x, int y)
{
	int r;
	int c;

	r = 0;
	while (r < tetri->width)
	{
		c = 0;
		while (c < tetri->height)
		{
			if (tetri->sh[c][r] == '#' && grid->map[y + c][x + r] != '.')
				return (0);
			c++;
		}
		r++;
	}
	fplace_grid(tetri, grid, create_xy(x, y), tetri->value);
	return (1);
}

/*
** This function takes a tetri struct, the grid, an x-y point on the grid,
** and the current letter value for the shape being read. It fills the grid,
** starting from the x-y point passed, with the letter value replacing each '#'
** of the tetri shape.
*/

void	fplace_grid(t_tetri *tetri, t_grid *grid, t_xy *pt, char val)
{
	int r;
	int c;

	r = 0;
	while (r < tetri->width)
	{
		c = 0;
		while (c < tetri->height)
		{
			if (tetri->sh[c][r] == '#')
				grid->map[pt->y + c][pt->x + r] = val;
			c++;
		}
		r++;
	}
	ft_memdel((void **)&pt);
}
