/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:13:24 by angkim            #+#    #+#             */
/*   Updated: 2019/03/16 10:05:17 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate (with malloc(3)) and returns a “fresh” string ending with ’\0’
** representing the integer n given as argument. Negative numbers must be
** supported. If the allocation fails, the function returns NULL.
*/

static char	*ft_inttostr(char *s, int n, int len)
{
	int i;

	i = 0;
	if (n == 0)
	{
		s[0] = '0';
		s[1] = '\0';
		return (s);
	}
	while (i < len)
	{
		if (n % 10 == 0 && n != 0)
			s[i] = '0';
		if (n % 10)
			s[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (s);
}

static char	*ft_strrev(char *s, int len)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
		i++;
	}
	return (s);
}

char		*ft_itoa(int n)
{
	char	*i_str;
	int		num;
	int		len;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	len = ft_digitcount(num);
	if (!(i_str = (char *)ft_memalloc(len + 1)))
		return (NULL);
	neg = 0;
	if (n < 0)
	{
		num *= -1;
		neg = 1;
	}
	ft_inttostr(i_str, num, len);
	ft_strrev(i_str, len);
	if (neg)
		i_str[0] = '-';
	return (i_str);
}
