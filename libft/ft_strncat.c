/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 20:30:43 by angkim            #+#    #+#             */
/*   Updated: 2019/03/11 22:42:59 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Appends not more than n characters from a copy of the null-terminated
** string s2 to the end of the null-terminated string s1, then adds a
** terminating '\0'. The string s1 must have sufficient space to hold the
** result. The source and destination strings should not overlap.
** Returns the pointer s1.
*/

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int i;
	unsigned int j;

	i = ft_strlen(s1);
	j = 0;
	while (j < n && s2[j])
	{
		s1[i] = s2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}
