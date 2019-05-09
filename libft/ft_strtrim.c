/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 22:52:32 by angkim            #+#    #+#             */
/*   Updated: 2019/03/16 08:23:56 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a copy of the string given as argument
** without whitespaces at the beginning or at the end of the string. Will be
** considered as whitespaces the following characters ’ ’, ’\n’ and ’\t’. If s
** has no whitespaces at the beginning or at the end, the function returns a
** copy of s. If the allocation fails the function returns NULL.
*/

char		*ft_strtrim(char const *s)
{
	char	*t_str;
	int		start;
	int		end;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_iswhitespace(s[start]))
		start++;
	end = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[end]))
	{
		end--;
		if (end < 0)
		{
			t_str = (char *)ft_memalloc(1);
			t_str[0] = '\0';
			return (t_str);
		}
	}
	t_str = (char *)ft_memalloc(end - start + 1);
	if (!t_str)
		return (NULL);
	t_str = ft_strsub(s, start, end - start + 1);
	return (t_str);
}
