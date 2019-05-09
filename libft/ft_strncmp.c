/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 21:25:28 by angkim            #+#    #+#             */
/*   Updated: 2019/03/11 23:14:02 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Lexicographically compares the NT strings s1 and s2. Compares not more than
** n characters. Characters that appear after a \0 are not compared. Comparison
** is done using unsigned characters. Returns an integer greater than, equal to,
** or less than 0, according to the difference in value between s1 and s2.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!n)
		return (0);
	i = 0;
	while ((s1[i] == s2[i]) && s1[i] && (i < n - 1))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
