/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:41:46 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 16:41:55 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function checks each shape is valid (20 or 21 characters). We iterate
** through each row at a time (i % 5 will check each character in a line) then
** we make sure there is a newline. We do this for each of the 4 lines. If the
** shape is the last shape in the file, the count will be 20 and it will not
** have a newline at the end.
*/

int		checkchar_shape(char *str, int count)
{
	int pieces;
	int i;

	pieces = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (-1);
			if (str[i] == '#' && ++pieces > 4)
				return (-2);
		}
		else if (str[i] != '\n')
			return (-3);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (-4);
	if (!(check_shape(str)))
		return (-5);
	return (0);
}

/*
** Checks that each shape read is a valid tetrimino. We do this by counting
** the number of sides touching. A valid tetrimino will have either 6 or 8.
*/

int		check_shape(char *str)
{
	int sides;
	int i;

	sides = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				sides++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				sides++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				sides++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				sides++;
		}
		i++;
	}
	if (sides == 6 || sides == 8)
		return (1);
	return (0);
}