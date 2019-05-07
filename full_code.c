#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft/libft.h"

// STRUCTS
typedef struct		s_xy
{
	int				x;
	int				y;
}					t_xy;

typedef struct		s_tetris
{
	char			**pos;
	int				width;
	int				height;
	char			value;
}					t_tetris;

typedef struct		s_grid
{
	int				size;
	char			**array;
}					t_grid;


// FUNCTION PROTOTYPES
t_list				*read_shapef(int fd);
int					read_checkshapef(int fd);
int					checkchar_shape(char *str, int count);
int					check_shape(char *str);
t_tetris			*alloc_shape(char *str, char value);
t_xy				*create_xy(int x, int y);
void				set_minmax(char *str, t_xy *min, t_xy *max);
t_tetris			*new_tetris_s(char **pos, int width, int height, char value);
void				ft_lstrev(t_list **list);
t_list				*free_list(t_list *list);
void				free_struct(t_tetris *tetris);

t_grid				*solve(t_list *list);
int					ft_lstsize(t_list *list);
int					top_sqrt(int n);
t_grid				*create_grid(int size);
int					solve_grid(t_grid *grid, t_list *list);
int					placep_grid(t_tetris *tetris, t_grid *grid, int x, int y);
void				fplace_grid(t_tetris *tetris, t_grid *grid, t_xy *point, char value);
void				print_grid(t_grid *grid);
void				free_grid(t_grid *grid);


// MAIN
int		main(int ac, char **av)
{
	t_list *list;
	t_grid *grid;

	if (ac != 2)
	{
		ft_putstr("Usage: fillit <input file>\n");
		return (1);
	}
	if ((list = read_shapef(open(av[1], O_RDONLY))) == NULL ||
			!(read_checkshapef(open(av[1], O_RDONLY))))
	{
		ft_putstr("error\n");
		return (1);
	}
	grid = solve(list);
	print_grid(grid);
	free_grid(grid);
	free_list(list);
	return (0);
}

// READ SHAPES, VALIDATE SHAPES/FILE, CREATE TETRIS STRUCTS, ADD TO LIST

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
	ft_lstrev(&list);
	return (list);
}

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

t_xy	*create_xy(int x, int y)
{
	t_xy	*point;
	
	point = (t_xy *)ft_memalloc(sizeof(t_xy));
	point->x = x;
	point->y = y;
	return (point);
}

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

t_tetris	*new_tetris_s(char **pos, int width, int height, char value)
{
	t_tetris	*tetris;

	tetris = (t_tetris *)ft_memalloc(sizeof(t_tetris));
	tetris->pos = pos;
	tetris->width = width;
	tetris->height = height;
	tetris->value = value;
	return (tetris);
}

// LIST REV, LIST SIZE, FREE LIST, FREE STRUCT
void	ft_lstrev(t_list **list)
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

int		ft_lstsize(t_list *list)
{
	int size;

	size = 0;
	while (list)
	{
		size++;
		list = list->next;
	}
	return (size);
}

t_list	*free_list(t_list *list)
{
	t_tetris	*tetris;
	t_list		*next;

	while (list)
	{
		tetris = (t_tetris *)list->content;
		free_struct(tetris);
		next = list->next;
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

void	free_struct(t_tetris *tetris)
{
	int y;

	y = 0;
	while (y < tetris->height)
	{
		ft_memdel((void **)&(tetris->pos[y]));
		y++;
	}
	ft_memdel((void **)&(tetris->pos));
	ft_memdel((void **)&tetris);
}

// SOLVE BY CREATING SMALLEST POSSIBLE GRID, PLACING PIECES, GROWING GRID IF NECESSARY
t_grid	*solve(t_list *list)
{
	t_grid *grid;
	int		size;

	size = top_sqrt(ft_lstsize(list) * 4);
	grid = create_grid(size);
	if (!(solve_grid(grid, list)))			// while VS if ?
	{
		size++;
		free_grid(grid);
		grid = create_grid(size);
	}
	return (grid);
}

int		top_sqrt(int n)
{
	int size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

t_grid	*create_grid(int size)
{
	t_grid	*grid;
	int		y;
	int		x;

	grid = (t_grid *)ft_memalloc(sizeof(t_grid));
	grid->size = size;
	grid->array = (char **)ft_memalloc(sizeof(char *) * size);
	y = 0;
	while (y < size)
	{
		grid->array[y] = ft_strnew(size);
		x = 0;
		while (x < size)
		{
			grid->array[y][x] = '.';
			x++;
		}
		y++;
	}
	return (grid);
}

int		solve_grid(t_grid *grid, t_list *list)
{
	t_tetris	*tetris;
	int			y;
	int			x;

	if (list == NULL)
		return (1);
	tetris = (t_tetris *)list->content;
	y = 0;
	while (y < grid->size - tetris->height + 1)
	{
		x = 0;
		while (x < grid->size - tetris->width + 1)
		{
			if (placep_grid(tetris, grid, x, y))
			{
				if (solve_grid(grid, list->next))
					return (1);
				else
					fplace_grid(tetris, grid, create_xy(x, y), '.');
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		placep_grid(t_tetris *tetris, t_grid *grid, int x, int y)
{
	int r;
	int c;

	r = 0;
	while (r < tetris->width)
	{
		c = 0;
		while (c < tetris->height)
		{
			if (tetris->pos[c][r] == '#' && grid->array[y + c][x + r] != '.')
				return (0);
			c++;
		}
		r++;
	}
	fplace_grid(tetris, grid, create_xy(x, y), tetris->value);
	return (1);
}

void	fplace_grid(t_tetris *tetris, t_grid *grid, t_xy *point, char value)
{
	int r;
	int c;

	r = 0;
	while (r < tetris->width)
	{
		c = 0;
		while (c < tetris->height)
		{
			// if (tetris->pos[c][r] == '#') ?
			grid->array[point->y + c][point->x + r] = value;
			c++;
		}
		r++;
	}
	// ft_memdel((void **)&point)
}

// PRINT AND FREE GRID
void	print_grid(t_grid *grid)
{
	int y;

	y = 0;
	while (y < grid->size)
	{
		ft_putstr(grid->array[y]);
		ft_putchar('\n');
		y++;
	}
}

void	free_grid(t_grid *grid)
{
	int y;

	y = 0;
	while (y < grid->size)
	{
		ft_memdel((void **)&(grid->array[y]));
		y++;
	}
	ft_memdel((void **)&(grid->array));
	ft_memdel((void **)&grid);
}
