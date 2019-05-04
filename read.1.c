/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:36:03 by angkim            #+#    #+#             */
/*   Updated: 2019/04/30 12:58:54 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_xy		*create_xy(int x, int y)
{
	t_xy *point;

	point = ft_memalloc(sizeof(t_xy));
	point->x = x;
	point->y = y;
	return (point);
}

void		set_minmax(char *str, t_xy *min, t_xy *max)
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

t_tetris	*new_tetris_s(char **pos, int width, int height, char value)
{
	t_tetris	*tetris;

	tetris = ft_memalloc(sizeof(t_tetris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

t_tetris	*alloc_shape(char *str, char value)
{
	t_xy		*min;
	t_xy		*max;
	char		**pos;
	t_tetris	*tetris;
	int			i;

	min = create_xy(3, 3);
	max = create_xy(0, 0);
	set_minmax(str, min, max);
	pos = ft_memalloc(sizeof(char *) * max->y - min->y + 1);
	i = 0;
	while (i < max->y - min->y + 1)
	{
		pos[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(pos[i], str + (min->x) + (i + min->y) * 5, max->x - min->x + 1);
		i++;
	}
	tetris = new_tetris_s(pos, max->x - min->x + 1, max->y - min->y + 1, value);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetris);
}

int			check_shape(char *str)
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

int			checkchar_shape(char *str, int b_read)
{
	int i;
	int pieces;
	
	i = 0;
	pieces = 0;
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
	if (b_read == 21 && str[20] != '\n')
		return (-4);
	if (!(check_shape(str)))
		return (-5);
	return (0);
}

void		free_struct(t_tetris *tetris)
{
	int y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)(&(tetris->pos[y])));
		y++;
	}
	ft_memdel((void **)&(tetris->pos));
	ft_memdel((void **)&tetris);
}

t_list		*free_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*next;

	while (list)
	{
		tetris = (t_tetris *)list->content;
		next = list->next;
		free_struct(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void		ft_lstrev(t_list **list)
{
	t_list *prev;
	t_list *current;
	t_list *next;

	prev = NULL;
	current = *list;
	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*list = prev;
}

t_list		*read_shapef(int fd)
{
	char		*buffer;
	int			b_read;
	t_list		*list;
	t_tetris	*tetris;
	char		output;

	buffer = ft_strnew(21);
	list = NULL;
	output = 'A';
	while ((b_read = read(fd, buffer, 21)) >= 20)
	{
		if (checkchar_shape(buffer, b_read) != 0
			|| (tetris = alloc_shape(buffer, output++)) == NULL)
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

int			read_checkshapef(int fd)
{
	char	*buffer;
	int		b_read;
	int		p_read;

	buffer = ft_strnew(21);
	while ((b_read = read(fd, buffer, 21)) >= 20)
		p_read = b_read;
	if (p_read == 21)
		return (0);
	return (1);
}