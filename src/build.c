/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 17:19:30 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/16 17:19:31 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
            build_P ??
            build_C ??  or build_PCE
            build_E ??

            build_background or build_map along with walls and junk
*/

void	paint_window(t_data *img, const int w, const int h)
/*Painting the whole window to cover asset background
4743554*/
{
	int	z;

    z = -1;
	while (++z < (w * h))
		img->addr[z] = 4743554;
}
