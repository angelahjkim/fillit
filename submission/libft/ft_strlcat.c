/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:54:33 by angkim            #+#    #+#             */
/*   Updated: 2019/03/12 09:53:47 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends string src to the end of dst. Takes the full size of the destination
** buffer and guarantees nul-termination if there is room (room for the NUL
** should be included in dstsize). Appends at most dstsize - strlen(dst) - 1
** characters. Then, nul-terminates, unless dstsize is 0 or the original
** dst string was longer than dstsize (should only occur if dstsize is
** incorrect or dst is not a proper string). Returns total length of the string
** it tried to create (intial length of dst + length of src).
*/

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dcpy;
	const char	*scpy;
	size_t		rem_size;
	size_t		dlen;

	dcpy = dst;
	scpy = src;
	rem_size = dstsize;
	while (rem_size-- && *dcpy)
		dcpy++;
	dlen = dcpy - dst;
	rem_size = dstsize - dlen;
	if (!rem_size)
		return (dlen + ft_strlen(src));
	while (*scpy)
	{
		if (rem_size != 1)
		{
			*dcpy++ = *scpy;
			rem_size--;
		}
		scpy++;
	}
	*dcpy = '\0';
	return (dlen + (scpy - src));
}
