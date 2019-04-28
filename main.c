/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:09:00 by angkim            #+#    #+#             */
/*   Updated: 2019/04/27 21:02:56 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** The first thing we need to do is read the file and check if it is valid.
** Next, we check if the shapes are valid. If either are invalid, we return
** an error message. Then, we want to store the shapes into a struct array
** which will contain information about each shape including its height,
** width, and a char array reflecting its shape. We now need to create a
** board to place the tetriminos onto. We want to start with the smallest
** board that can fit all our tetriminos.
*/

#include <stdio.h>		// delete after testing

void	ft_lstprint(t_list **list)
{
	t_list 		*cur;
	t_tetris	*tet_cur;
	int			y;

	cur = *list;
	while (cur != NULL)
	{
		tet_cur = cur->content;
		y = 0;
		while (y < tet_cur->height)
		{
			printf("%s\n", tet_cur->pos[y]);
			y++;
		}
		printf("\n");
		cur = cur->next;
	}
}

int     main(int ac, char **av)
{
	t_list	*list;
	t_grid	*grid;

	if (ac != 2)
	{
		ft_putstr("Usage: fillit <input file>\n");
		return (1);
	}
	if ((list = read_shapef(open(av[1], O_RDONLY))) == NULL ||
			!(read_checkshapef(open(av[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (1);
	}

	// for testing -- delete
	ft_lstprint(&list);

	grid = solve(list);
	print_grid(grid);
	free_grid(grid);
	free_list(list);
    return (0);
}
