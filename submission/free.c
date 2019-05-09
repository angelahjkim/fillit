/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:28:57 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 16:29:19 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_lstsize(t_list *list)
{
	int size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

t_list	*free_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*next;

	while (list)
	{
		tetris = (t_tetris *)list->content;
		free_struct(tetris);
		next = list->next;
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	free_struct(t_tetris *tetris)
{
	int y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)&(tetris->pos[y]));
		y++;
	}
	ft_memdel((void **)&(tetris->pos));
	ft_memdel((void **)&tetris);
}

void	free_grid(t_grid *grid)
{
	int y;

	y = 0;
	while (y < grid->size)
	{
		ft_memdel((void **)&(grid->array[y]));
		y++;
	}
	ft_memdel((void **)&(grid->array));
	ft_memdel((void **)&grid);
}