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

int     key_press(int key)
{
        printf("key = %d\n", key);
        if (key == KEY_ESC) //esc key
                exit(0);
        return (0);
}


int     key_close(int key) //top left corner red 'x'
{
        (void)key;
        exit(0);
        return (0);
}
