/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 17:51:06 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/24 17:51:07 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int ft_gameover(t_elements *g)
{
    void    *poster;

    poster = NULL;
    if (g->map.C == -1)
    {
        mlx_clear_window(g->mlx, g->win_p);
        // mlx_put_image_to_window(g->mlx, g->win_p, g->floor.p, 0, 0);
        mlx_string_put(g->mlx, g->win_p, (g->win_w / 2) - 100, g->win_h / 3, 0xFF0000, "GAME     OVER!");
        clear_map(g->map.addr);
        g->map.C--;
    }
    return (0);
}

static void update_moves(t_elements *g, int i)
{
    static int  n;
    int         r;
    char        *num;

    n += i;
    printf("Movements: %d\ncollectibles: %d\n", n,g->map.C);
    r = mlx_put_image_to_window(g->mlx, g->win_p, g->wall.p, 0, 0); // maybe somethn like check(mlx_put_image...)
    num = ft_itoa(n);
    mlx_string_put(g->mlx, g->win_p, 100, 70, 0x0000FF, "Mov: ");
    mlx_string_put(g->mlx, g->win_p, 120, 90, 0x0000FF, num);
    free(num);
    if (!r)
        display_err(clear_map(g->map.addr)); // destroy images and window ????
}

static void     ft_move(t_elements *g, int y, int x, char *position)
{
    if (g->map.addr[y][x] == '1')
        return ;
    if (g->map.addr[y][x] == 'C')
        g->map.C--;
    if (*position != 'E')
        *position = '0';
    if (g->map.addr[y][x] == 'E')
    {
        if (g->map.C == 0)
            g->map.C--;
    }
    else
       g->map.addr[y][x] = 'P';
    g->map.Px = x;
    g->map.Py = y;
    mlx_clear_window(g->mlx, g->win_p);
    if (!mlx_put_image_to_window(g->mlx, g->win_p, g->floor.p, 0, 0)) //painting empty space
		display_err(clear_map(g->map.addr));
    put_to_window(g, -1, 1);
    update_moves(g, 1);
}

int     key_press(int key, t_elements *g) 
/*Needs free up memory and destroy everything ?? 
    Can't just count arrow presses, what if there's a wall ?????? <------------------CORRECT!!!!!!!
    */
{
    char    *p;

    p = NULL;
    if (key == KEY_ESC || key == X_BUTTON_EXIT) //esc key
    {
        mlx_destroy_window(g->mlx, g->win_p);
        if (g->map.C >= -1)
            clear_map(g->map.addr);
        exit(0);
    }
    if (g->map.C <= -1)
        return (ft_gameover(g));
    p = &g->map.addr[g->map.Py][g->map.Px];
    if (key == UP)
        ft_move(g, g->map.Py - 1, g->map.Px, p);
    else if (key == DOWN)
        ft_move(g, g->map.Py + 1, g->map.Px, p);
    else if (key == LEFT)
        ft_move(g, g->map.Py, g->map.Px - 1, p);
    else if (key == RIGHT)
        ft_move(g, g->map.Py, g->map.Px + 1, p);
    return (0);
}


int     key_close(int key, t_elements *g) 
/*top left corner red 'x'
    Segfaulting with any of both funtions for some reason*/
{
    (void)key;
    clear_map(g->map.addr);
    mlx_destroy_window(g->mlx, g->win_p);
    exit(0);
    // return (0);
}