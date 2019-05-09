/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:27:00 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 18:56:59 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** In our main function we first check to make sure one argument (input file)
** is passed to our program - if not we return a message with usage info. Then
** we open the input file and pass it to two checker functions. The second
** simply checks that the file is valid and the first checks that the shapes
** in the file are valid. If they are, we save each shape into a tetris struct
** and save add them to our list. We then pass our list to functions that
** create a grid where we place our shapes, see if they fit, and output the
** solved grid. Finally, we free our grid and list structs.
*/

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

/*
** Because our ft_lstadd function in our libft adds list elements to the
** beginning of the list, our list will be in reverse-order. We use this
** function to reverse the list to match the order of the shapes read from
** the input file.
*/

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
