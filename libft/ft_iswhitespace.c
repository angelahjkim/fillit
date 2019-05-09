/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 08:46:20 by angkim            #+#    #+#             */
/*   Updated: 2019/03/12 09:32:56 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Checks if a character is a space, vertical/horizontal tab, carriage return,
** or form feed. Returns 1 if true, 0 if false.
*/

int		ft_iswhitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r' ||
			c == '\n')
		return (1);
	else
		return (0);
}
