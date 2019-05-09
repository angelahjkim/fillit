/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:27:00 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 16:46:00 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_list *list;
	t_grid *grid;

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
	grid = solve(list);
	print_grid(grid);
	free_grid(grid);
	free_list(list);
	return (0);
}

void	ft_lstrev(t_list **list)
{
	t_list *prev;
	t_list *current;
	t_list *next;

	prev = NULL;
	current = *list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list = prev;
}