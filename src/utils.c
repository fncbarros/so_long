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

	dst = img->addr + ft_offset(x, y, *img);
	*(unsigned int *)dst = color;
}

static void	init_data(t_data *obj)
/*Creating all images I_SIZE x I_SIZE */
{
	obj->p = NULL;
	obj->w = I_SIZE;
	obj->h = I_SIZE;
	obj->addr = NULL;
	obj->bpp = 0;
	obj->line = 0;
	obj->endian = 0;
}

void	*g_init(t_elements *g)
{
	g->win_p = NULL;
	g->win_h = 0;
	g->win_w = 0;
	g->map.C = 0;
	g->map.columns = 0;
	g->map.rows = -1;
	init_data(&g->floor);
	init_data(&g->wall);
	init_data(&g->P);
	init_data(&g->C);
	init_data(&g->E);
	return (NULL);
}

/*
void	ft_close(t_elements *g)
{
		mlx_destroy_image(g->mlx, g->floor.p)
		mlx_destroy_image(g->mlx, g->wall.p)
		mlx_destroy_image(g->mlx, g->P.p)
		mlx_destroy_image(g->mlx, g->C.p)
		mlx_destroy_image(g->mlx, g->E.p)
		mlx_destroy_window(g->mlx, g->win_p);
		if (g->map.C >= -1)
			clear_map(g->map.addr);
		exit(0);
}*/