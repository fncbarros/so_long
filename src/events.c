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

static void update_moves(t_elements *g, int i)
{
    static int  n;
    int         r;
    char        *num;

    n += i;
    printf("Movements: %d\n", n);
    r = mlx_put_image_to_window(g->mlx, g->win_p, g->wall.p, 0, 0); // maybe somethn like check(mlx_put_image...)
    num = ft_itoa(n);
    r = mlx_string_put(g->mlx, g->win_p, 100, 70, 0xFF0000, "Mov: ");
    r = mlx_string_put(g->mlx, g->win_p, 120, 90, 0xFF0000, num);
    free(num);
    if (!r)
        display_err(clear_map(g->map.addr)); // destroy images and window ????
}

int     ft_move(t_elements *g, int y, int x, char *position)
{
    if (g->map.addr[y][x] == '1')
        return (0);
    g->map.addr[y][x] = 'P';
    *position = '0';
    put_to_window(g, y, 1);
    update_moves(g, 1);
    return (1); //??
}

int     key_press(int key, t_elements *g) 
/*Needs free up memory and destroy everything ?? 
    Can't just count arrow presses, what if there's a wall ?????? <------------------CORRECT!!!!!!!
    */
{
    char    *p;

    p = &g->map.addr[g->map.Py][g->map.Px];
    mlx_put_image_to_window(g->mlx, g->win_p, g->floor.p, 0, I_SIZE); //<-----------TEST!!!!!!!!!!
    if (key == KEY_ESC) //esc key
    {
        mlx_destroy_window(g->mlx, g->win_p);
        clear_map(g->map.addr);
        exit(0);
    }
    if (key == UP)
        ft_move(g, --g->map.Py, g->map.Px, p);
        // g->map.Py--; // 
    else if (key == DOWN)
        ft_move(g, ++g->map.Py, g->map.Px, p);
        // g->map.Py++; // 
    else if (key == LEFT)
        ft_move(g, g->map.Py, --g->map.Px, p);
        // g->map.Px--; // 
    else if (key == RIGHT)
        ft_move(g, g->map.Py, ++g->map.Px, p);
        /*g->map.Px++;*/
    // if (g->map.addr[g->map.Py][g->map.Px] == '1')
    //     return (0);
    // g->map.addr[y][x] = 'P';
    // *position = '0';
    // put_to_window(g, y, 1);
    // update_moves(g, 1);








    // if (key == LEFT) //esc key
        // mlx_put_image_to_window(g->mlx, g->win_p, g->P.p, ??, ??);
    // printf("Movements: %d\n", n);
    // r = mlx_put_image_to_window(g->mlx, g->win_p, g->wall.p, 0, 0); // maybe somethn like check(mlx_put_image...)
    // num = ft_itoa(n);
    // r = mlx_string_put(g->mlx, g->win_p, 100, 70, 0xFF0000, "Mov: ");
    // r = mlx_string_put(g->mlx, g->win_p, 120, 90, 0xFF0000, num);
    // free(num);


    return (0);
}


int     key_close(int key, t_elements *g) //top left corner red 'x'
{
        printf("key = %d\n", key);
        mlx_destroy_window(g->mlx, g->win_p);
        clear_map(g->map.addr);
        exit(0);
        return (0);
}
