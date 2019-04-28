/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angkim <angkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 16:36:09 by angkim            #+#    #+#             */
/*   Updated: 2019/04/27 20:59:57 by angkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     ft_lstsize(t_list *list)
{
    int i;

    i = 0;
    while (list != NULL)
    {
        i++;
        list = list->next;
    }
    return (i);
}

int     top_sqrt(int n)
{
    int size;

    size = 2;
    while (size * size < n)
        size++;
    return (size);
}

t_grid  *create_grid(int size)
{
    t_grid  *grid;
    int     c;
    int     r;

    grid = (t_grid *)ft_memalloc(sizeof(t_grid));
    grid->size = size;
    grid->array = (char **)ft_memalloc(sizeof(char *) * size);
    c = 0;
    while (c < size)
    {
        grid->array[c] = ft_strnew(size);
        r = 0;
        while (r < size)
        {
            grid->array[c][r] = '.';
            r++;
        }
        c++;
    }
    return (grid);
}

void     fplace_grid(t_tetris *tetris, t_grid *grid, t_xy *point, char value)
{
    int c;
    int r;

    r = 0;
    while (r < tetris->width)
    {
        c = 0;
        while (c < tetris->height)
        {
            if (tetris->pos[c][r] == '#')
                grid->array[point->y + c][point->x + r] = value;
            c++;
        }
        r++;
    }
    ft_memdel((void **)&point);
}

int     placep_grid(t_tetris *tetris, t_grid *grid, int x, int y)
{
    int c;
    int r;

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

int     solve_grid(t_grid *grid, t_list *list)
{
    t_tetris    *tetris;
    int         x;
    int         y;

    if (list == NULL)
        return (1);
    y = 0;
    tetris = (t_tetris *)(list->content);
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

void    free_grid(t_grid *grid)
{
    int i;

    i = 0;
    while (i < grid->size)
    {
        ft_memdel((void **)&(grid->array[i]));
        i++;
    }
    ft_memdel((void **)&(grid->array));
    ft_memdel((void **)&grid);
}

void    print_grid(t_grid *grid)
{
    int i;

    i = 0;
    while (i < grid->size)
    {
        ft_putstr(grid->array[i]);
        ft_putchar('\n');
        i++;
    }
}

t_grid  *solve(t_list *list)
{
    t_grid  *grid;
    int     size;

    size = top_sqrt(ft_lstsize(list) * 4);
    grid = create_grid(size);

    while (!solve_grid(grid, list))
    {
        size++;
        free_grid(grid);
        grid = create_grid(size);
    }

   return (grid);
}