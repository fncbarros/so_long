/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 16:05:02 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/15 16:05:04 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_offset(int x, int y, const t_data data)
{
	return (((y * data.line) + x * (data.bpp / 8)) / 4);
}

void	ft_img_pixel_put(t_data *img, int color, int x, int y)
{
	int	*dst;

	dst = img->addr + ft_offset(x, y, *img); /*img->addr is an int *, that's why it's segfaulting*/
	*(unsigned int *)dst = color;
}

void	*img_init(t_data *img)
/*Not sure*/
{
	img->addr = NULL;
	img->bpp = 0;
	img->line = 0;
	img->endian = 0;
	img->img.w = 0;
	img->img.w = 0;
	return (NULL);
}
