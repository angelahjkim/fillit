/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:31:10 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 16:37:08 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_xy	*create_xy(int x, int y)
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

t_tetris	*new_tetris_s(char **pos, int width, int height, char value)
{
	t_tetris	*tetris;

	tetris = (t_tetris *)ft_memalloc(sizeof(t_tetris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_grid	*create_grid(int size)
{
	t_grid	*grid;
	int		y;
	int		x;

	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	grid->array = (char **)ft_memalloc(sizeof(char *) * size);
	y = 0;
	while (y < size)
	{
		grid->array[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			grid->array[y][x] = '.';
			x++;
		}
		y++;
	}
	return (grid);
}

void	print_grid(t_grid *grid)
{
	int y;

	y = 0;
	while (y < grid->size)
	{
		ft_putstr(grid->array[y]);
		ft_putchar('\n');
		y++;
	}
}
