/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 22:52:43 by angkim            #+#    #+#             */
/*   Updated: 2019/03/04 12:19:41 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** output the string s to the file descriptor fd
*/

void	ft_putstr_fd(char const *s, int fd)
{
	while (s && *s)
	{
		write(fd, s, 1);
		s++;
	}
}
