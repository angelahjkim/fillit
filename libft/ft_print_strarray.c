/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strarray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 17:39:41 by angkim            #+#    #+#             */
/*   Updated: 2019/03/16 08:44:03 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** takes a string array and its size as arguments and displays each string
** followed by a newline character
*/

void	ft_print_strarray(char **array, int size)
{
	int i;

	i = 0;
	while (array && i < size)
	{
		ft_putstr((char const *)array[i]);
		ft_putchar('\n');
		i++;
	}
}
