/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:26:50 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 16:46:24 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** We know that each shape is composed of 4 pieces. To find the smallest
** possible grid that could fit our shape(s) we decided to multiply the number
** of shapes by 4 and then take the square root of the result to be the grid
** length. If the shapes cannot be placed into the grid, we increase the size
** until we get a large enough grid that can hold all the shapes.
*/

t_grid	*solve(t_list *list)
{
	t_grid *grid;
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

int		solve_grid(t_grid *grid, t_list *list)
{
	t_tetris	*tetris;
	int			y;
	int			x;

	if (list == NULL)
		return (1);
	tetris = (t_tetris *)list->content;
	y = 0;
	while (y < grid->size - tetris->height + 1)
	{
		x = 0;
		while (x < grid->size - tetris->width + 1)
		{
			if (placep_grid(tetris, grid, x, y))
			{
				if (solve_grid(grid, list->next))
					return (1);
				else
					fplace_grid(tetris, grid, create_xy(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		placep_grid(t_tetris *tetris, t_grid *grid, int x, int y)
{
	int r;
	int c;

	r = 0;
	while (r < tetris->width)
	{
		c = 0;
		while (c < tetris->height)
		{
			if (tetris->pos[c][r] == '#' && grid->array[y + c][x + r] != '.')
				return (0);
			c++;
		}
		r++;
	}
	fplace_grid(tetris, grid, create_xy(x, y), tetris->value);
	return (1);
}

void	fplace_grid(t_tetris *tetris, t_grid *grid, t_xy *point, char value)
{
	int r;
	int c;

	r = 0;
	while (r < tetris->width)
	{
		c = 0;
		while (c < tetris->height)
		{
			if (tetris->pos[c][r] == '#')
				grid->array[point->y + c][point->x + r] = value;
			c++;
		}
		r++;
	}
	ft_memdel((void **)&point);
}
