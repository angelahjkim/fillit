/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 23:07:13 by angkim            #+#    #+#             */
/*   Updated: 2019/03/10 16:23:39 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates sufficient memory for a copy of s1, does the copy, and returns
** a pointer to it. (The pointer may subsequently be used as an argument to
** the function free).
*/

char	*ft_strdup(const char *s1)
{
	char	*s1_copy;

	if (!(s1_copy = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1)))
		return (NULL);
	return (ft_strcpy(s1_copy, s1));
}
