/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:31:10 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 18:23:23 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Stores x and y coordinates which represent a particular point in our grid.
*/

t_xy		*create_xy(int x, int y)
{
	t_xy	*point;

	point = (t_xy *)ft_memalloc(sizeof(t_xy));
	point->x = x;
	point->y = y;
	return (point);
}

/*
** Allocates memory for a tetris struct and assigns the appropriate data
** to each of the variables that define the tetrimino.
*/

t_tetri		*new_tetri_s(char **sh, int width, int height, char value)
{
	t_tetri	*tetri;

	tetri = (t_tetri *)ft_memalloc(sizeof(t_tetri));
	tetri->sh = sh;
	tetri->width = width;
	tetri->height = height;
	tetri->value = value;
	return (tetri);
}

/*
** Using the size value passed to the function, we create a 2D array of that
** size in length and height and fill each position with a '.'.
*/

t_grid		*create_grid(int size)
{
	t_grid	*grid;
	int		y;
	int		x;

	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	grid->map = (char **)ft_memalloc(sizeof(char *) * size);
	y = 0;
	while (y < size)
	{
		grid->map[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			grid->map[y][x] = '.';
			x++;
		}
		y++;
	}
	return (grid);
}

/*
** Once the grid is filled and solved, this function prints the result.
*/

void		print_grid(t_grid *grid)
{
	int y;

	y = 0;
	while (y < grid->size)
	{
		ft_putstr(grid->map[y]);
		ft_putchar('\n');
		y++;
	}
}
