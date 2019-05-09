/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 23:40:29 by angkim            #+#    #+#             */
/*   Updated: 2019/03/16 08:27:38 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns an array of “fresh” strings
** (all ending with ’\0’, including the array itself) obtained by spliting s
** using the character c as a delimiter.
** If the allocation fails the function returns NULL.
*/

char		**ft_strsplit(char const *s, char c)
{
	char	**word_array;
	int		array_size;
	int		i;
	int		end;

	array_size = ft_wordcount(s, c);
	if (!(word_array = (char **)ft_memalloc(sizeof(char *) * (array_size + 1))))
		return (NULL);
	i = 0;
	while (i < array_size)
	{
		while (*s && *s == c)
			s++;
		end = ft_wordlen(s, c);
		if (!(word_array[i] = ft_strsub(s, 0, end)))
			return (NULL);
		s += end;
		i++;
	}
	word_array[i] = NULL;
	return (word_array);
}
