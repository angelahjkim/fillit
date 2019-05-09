/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 09:49:52 by angkim            #+#    #+#             */
/*   Updated: 2019/03/12 09:51:55 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** locate the first occ of NT str s_find in NT str s
** not more than len characters are searched; chars after \0 not searched
** returns s if s_find empty, ptr to first occ in s_find, or NULL
*/

char	*ft_strnstr(const char *s, const char *s_find, size_t len)
{
	size_t i;
	size_t j;

	if (!*s_find)
		return ((char *)s);
	i = 0;
	while (s[i])
	{
		j = 0;
		while (*(s_find + j) == *(s + i + j) && i + j < len && s_find[j])
			j++;
		if (!*(s_find + j))
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
