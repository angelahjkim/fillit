/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:27:09 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 16:28:19 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** This function reads from the input file each shape at a time. A shape
** is defined in an input structure of 20 or 21 characters depending on
** whether it the last shape or not. If the final read returns a value
** greater than 0 but less than 20, it is an invalid file and we return
** an error. Otherwise, we use each read to allocate a tetris struct
** and add that struct to our list.
*/

t_list	*read_shapef(int fd)
{
	char		*buffer;
	int			b_read;
	char		output;
	t_list		*list;
	t_tetris	*tetris;

	buffer = ft_strnew(21);
	list = NULL;
	output = 'A';
	while ((b_read = read(fd, buffer, 21)) >= 20)
	{
		if (checkchar_shape(buffer, b_read) < 0 ||
				(tetris = alloc_shape(buffer, output++)) == NULL)
		{
			ft_memdel((void **)&buffer);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_tetris)));
		ft_memdel((void **)&tetris);
	}
	ft_memdel((void **)&buffer);
	(b_read != 0) ? (free_list(list)) : 0;
	ft_lstrev(&list);
	return (list);
}

/*
** Our shape is read into a string containing 16 characters (of which only 4
** make up the shape itself). We need to create a 2D array that contain only
** the characters that make up the shape. To make our 2D array, we use x and y
** coordinate values. We need to determine these values from our input string
** by recognizing that each "row" contains 5 bytes, and each multiple of 5
** represents the position in the "row" below.

** To allocate our shape, we need to isolate the shape from the input structure
** by finding the min and max x and y coordinates of the '#' characters and
** storing those bytes into a new 2D array which we call "pos." Then we also
** need to store the width, height, and character value of each shape into our
** tetris struct which then gets added to our list.
*/

t_tetris	*alloc_shape(char *str, char value)
{
	t_xy		*min;
	t_xy		*max;
	char		**pos;
	int			i;
	t_tetris	*tetris;

	min = create_xy(3, 3);
	max = create_xy(0, 0);
	set_minmax(str, min, max);
	pos = (char **)ft_memalloc(sizeof(char *) * max->y - min->y + 1);
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + min->x + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetris = new_tetris_s(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetris);
}

/*
** Each tetrimino is represented by a string of 20 or 21 characters which
** include extra '.'s. We want to store only the characters that represent the
** tetrimino itself. To do this we need to find where the tetrimino starts in
** the string and where it ends and store only those characters into a string
** pointed to by our struct.
*/

void	set_minmax(char *str, t_xy *min, t_xy *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

/*
** Checks that each input structure is 4 lines of 4 characters followed by
** a newline (except the last structure which has no newline)
*/

int		read_checkshapef(int fd)
{
	char	*buffer;
	int		b_read;
	int		l_read;
	
	buffer = ft_strnew(21);
	while ((b_read = read(fd, buffer, 21)) >= 20)
		l_read = b_read;
	if (l_read == 21)
		return (0);
	return (1);
}
