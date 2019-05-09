/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 16:31:41 by angkim            #+#    #+#             */
/*   Updated: 2019/05/08 19:01:02 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct	s_xy
{
	int			x;
	int			y;
}				t_xy;

typedef struct	s_tetri
{
	char		**sh;
	int			width;
	int			height;
	char		value;
}				t_tetri;

typedef struct	s_grid
{
	int			size;
	char		**map;
}				t_grid;

t_list			*read_shapef(int fd);
int				read_checkshapef(int fd);
int				checkchar_shape(char *str, int count);
int				check_shape(char *str);
t_tetri			*alloc_shape(char *str, char value);
t_xy			*create_xy(int x, int y);
void			set_minmax(char *str, t_xy *min, t_xy *max);
t_tetri			*new_tetri_s(char **sh, int width, int height, char value);
void			ft_lstrev(t_list **list);
t_list			*free_list(t_list *list);
void			free_struct(t_tetri *tetri);
t_grid			*solve(t_list *list);
int				ft_lstsize(t_list *list);
int				top_sqrt(int n);
t_grid			*create_grid(int size);
int				solve_grid(t_grid *grid, t_list *list);
int				placep_grid(t_tetri *tetri, t_grid *grid, int x, int y);
void			fplace_grid(t_tetri *tetri, t_grid *grid, t_xy *pt, char val);
void			print_grid(t_grid *grid);
void			free_grid(t_grid *grid);

#endif
