/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 11:13:26 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/14 11:13:29 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

int get_trgb(int trgb, char color)
{
    if (color == 't' || color == 'T')
        return (trgb & (0xFF << 24));
    if (color == 'r' || color == 'R')
        return (trgb & (0xFF << 16));
    if (color == 'g' || color == 'G')
        return (trgb & (0xFF << 8));
    if (color == 'b' || color == 'B')
        return (trgb & 0xFF);
    return (0);
}

int add_shade(double distance, int color)
{
    
}

int main(void)
{

}