/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:00:10 by angkim            #+#    #+#             */
/*   Updated: 2019/03/10 19:09:56 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Copies at most len characters from src to dst. If src is less than len
** characters long, the remainder of dst is filled with '\0' characters.
** Otherwise, dst does not terminate.
*/

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (i < len && src[i])
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	while (j < len)
	{
		dst[j] = '\0';
		j++;
	}
	return (dst);
}
