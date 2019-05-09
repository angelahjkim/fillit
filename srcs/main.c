/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:27:00 by angkim            #+#    #+#             */
/*   Updated: 2019/05/09 10:07:14 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** The goal of our program is to create an algorithm that can arrange up to 26
** tetrimino shapes into the smallest possible square. The program is passed
** a file that contains each piece in a matrix of 4 x 4 characters with
** matrices separated by an empty line.
**
** We first read the file, validate it and each of the shapes. Then we create
** a struct that describes each shape and store it into a linked list which
** we can use to then feed the shapes into our algorithm.
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
