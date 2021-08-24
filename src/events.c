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

int     key_press(int key, t_elements *g) 
/*Needs free up memory and destroy everything ?? 
    Can't just count arrow presses, what if there's a wall ?????? <------------------CORRECT!!!!!!!
    */
{
    static int  n;
    char    *num;
    int     r;


    if (key == KEY_ESC) //esc key
    {
        mlx_destroy_window(g->mlx, g->win_p);
        clear_map(g->map.addr);
        exit(0);
    }
    if (key == UP)
        n++;
    if (key == DOWN)
        n++;
    if (key == LEFT)
        n++;
    if (key == RIGHT)
        n++;
    // if (key == LEFT) //esc key
        // mlx_put_image_to_window(g->mlx, g->win_p, g->P.p, ??, ??);
    printf("Movements: %d\n", n);
    r = mlx_put_image_to_window(g->mlx, g->win_p, g->wall.p, 0, 0); // maybe somethn like check(mlx_put_image...)
    num = ft_itoa(n);
    r = mlx_string_put(g->mlx, g->win_p, 100, 70, 0xFF0000, "Mov: ");
    r = mlx_string_put(g->mlx, g->win_p, 120, 90, 0xFF0000, num);
    free(num);
    // if (!r)
        // display_err(clear_map(g->map.addr)); // destroy images and window ????
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
