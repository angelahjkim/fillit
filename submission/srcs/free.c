/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:28:57 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 18:23:35 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_list	*free_list(t_list *list)
{
	t_tetri		*tetri;
	t_list		*next;

	while (list)
	{
		tetri = (t_tetri *)list->content;
		free_struct(tetri);
		next = list->next;
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	free_struct(t_tetri *tetri)
{
	int y;

	y = 0;
	while (y < tetri->height)
	{
		ft_memdel((void **)&(tetri->sh[y]));
		y++;
	}
	ft_memdel((void **)&(tetri->sh));
	ft_memdel((void **)&tetri);
}

void	free_grid(t_grid *grid)
{
	int y;

	y = 0;
	while (y < grid->size)
	{
		ft_memdel((void **)&(grid->map[y]));
		y++;
	}
	ft_memdel((void **)&(grid->map));
	ft_memdel((void **)&grid);
}
