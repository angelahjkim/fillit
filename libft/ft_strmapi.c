/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 16:41:34 by angkim            #+#    #+#             */
/*   Updated: 2019/03/12 12:25:02 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string passed as argument by
** giving its index as first argument to create a “fresh” new string
** (with malloc) resulting from the successive applications of f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	if (s && f)
	{
		new_str = (char *)ft_memalloc(ft_strlen(s) + 1);
		if (new_str)
		{
			i = 0;
			while (s[i])
			{
				new_str[i] = f(i, s[i]);
				i++;
			}
			new_str[i] = '\0';
		}
		return (new_str);
	}
	return (0);
}
