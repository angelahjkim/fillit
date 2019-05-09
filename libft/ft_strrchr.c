/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:15:39 by angkim            #+#    #+#             */
/*   Updated: 2019/03/11 15:52:50 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Locates the last occurrence of c (converted to a char) in the string
** pointed to by s. Nul-terminating character inclusive. Returns a pointer to
** the located character or NULL if the character does not appear in s.
*/

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len >= 0)
	{
		if (*(s + len) == (unsigned char)c)
			return ((char *)s + len);
		len--;
	}
	return (NULL);
}
