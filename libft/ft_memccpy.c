/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:05:38 by angkim            #+#    #+#             */
/*   Updated: 2019/03/10 16:00:17 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies bytes from string src to dst. If the character c (as converted to
** an unsigned char) occurs in string src, the copy stops and a pointer to the
** byte after the copy of c in the string dst is returned. Otherwise, n bytes
** are copied, and a NULL pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*cdst;
	unsigned char	*csrc;

	cdst = (unsigned char *)dst;
	csrc = (unsigned char *)src;
	while (n--)
	{
		*cdst = *csrc;
		if (*cdst == (unsigned char)c)
		{
			cdst++;
			return (cdst);
		}
		cdst++;
		csrc++;
	}
	return (NULL);
}
