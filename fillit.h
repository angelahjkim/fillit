/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 16:08:09 by angkim            #+#    #+#             */
/*   Updated: 2019/04/27 20:51:39 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/includes/libft.h"

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_tetris
{
	char		**pos;
	int			width;
	int			height;
	char		value;
}				t_tetris;

typedef struct	s_grid
{
	int			size;
	char		**array;
}				t_grid;


t_list			*read_shapef(int fd);
int				read_checkshapef(int fd);

int				checkchar_shape(char *str, int count);
int				check_shape(char *str);

t_tetris		*new_tetris_s(char **pos, int width, int height, char value);
t_tetris		*alloc_shape(char *str, char value);
t_xy			*create_xy(int x, int y);
void			set_minmax(char *str, t_xy *min, t_xy *max);

t_grid			*solve(t_list *list);
int				top_sqrt(int n);
t_grid			*create_grid(int size);
int				solve_grid(t_grid *grid, t_list *list);
int				placep_grid(t_tetris *tetris, t_grid *grid, int x, int y);
void			fplace_grid(t_tetris *tetris, t_grid *grid, t_xy *point, char value);
void			print_grid(t_grid *grid);

// add to libft
int				ft_lstsize(t_list *list);
void			ft_lstrev(t_list **list);
t_list			*free_list(t_list *list);

void			free_struct(t_tetris *tetris);
void			free_grid(t_grid *grid);

// for testing only
void	ft_lstprint(t_list **list);

#endif
