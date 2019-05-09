/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 23:49:46 by angkim            #+#    #+#             */
/*   Updated: 2019/03/10 15:40:38 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** write len bytes of value c (converted to an unsigned char) to the string b.
** returns pointer to b.
*/

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_cpy;

	b_cpy = (unsigned char *)b;
	while (len--)
	{
		*b_cpy = c;
		b_cpy++;
	}
	return (b);
}
