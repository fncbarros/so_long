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

static void	paint_floor(t_data *img, const int w, const int h, int color)
{
	int	z;

	z = -1;
	while (++z < (w * h))
		img->addr[z] = color;
}

void	setup_game(t_elements *g)
/*A little too much code...*/
{
	g->wall.p = mlx_xpm_file_to_image(g->mlx,
			"img/wall.xpm", &g->wall.w, &g->wall.h);
	g->wall.addr = (int *)mlx_get_data_addr(g->wall.p, &g->wall.bpp,
			&g->wall.line, &g->wall.endian);
	g->win_w = g->map.columns * g->wall.w;
	g->win_h = g->map.rows * g->wall.h;
	g->floor.h = g->win_h;
	g->floor.w = g->win_w;
	g->floor.p = mlx_new_image(g->mlx, g->floor.w, g->floor.h);
	g->floor.addr = (int *)mlx_get_data_addr(g->floor.p,
			&g->floor.bpp, &g->floor.line, &g->floor.endian);
	paint_floor(&g->floor, g->floor.w, g->floor.h, FLOOR);
	g->P.p = mlx_xpm_file_to_image(g->mlx,
			"img/Marvin.xpm", &g->P.w, &g->P.h);
	g->P.addr = (int *)mlx_get_data_addr(g->P.p, &g->P.bpp,
			&g->P.line, &g->P.endian);
	g->C.p = mlx_xpm_file_to_image(g->mlx,
			"img/petunias.xpm", &g->C.w, &g->C.h);
	g->C.addr = (int *)mlx_get_data_addr(g->C.p, &g->C.bpp,
			&g->C.line, &g->C.endian);
	g->E.p = mlx_xpm_file_to_image(g->mlx,
			"img/heart_of_gold.xpm", &g->E.w, &g->E.h);
	g->E.addr = (int *)mlx_get_data_addr(g->E.p, &g->E.bpp,
			&g->E.line, &g->E.endian);
	// check for NULLs
}

static void	*new_floor(t_elements *g)
/*Stupidest shit ever. Couldn't shrink floor image size any other way*/
{
	t_data	tmp;

	tmp.p = mlx_new_image(g->mlx, I_SIZE, I_SIZE);
	tmp.addr = (int *)mlx_get_data_addr(tmp.p,
			&tmp.bpp, &tmp.line, &tmp.endian);
	paint_floor(&tmp, I_SIZE, I_SIZE, FLOOR);
	g->floor.h = I_SIZE;
	g->floor.w = I_SIZE;
	g->floor.addr = tmp.addr;
	g->floor.line = tmp.line;
	return (tmp.p);
}

void	put_to_window(t_elements *g, int i, int ret)
{
	int	j;

	g->floor.p = new_floor(g);
	while (i < g->map.rows)
	{
		j = -1;
		while (++j < g->map.columns)
		{
			if (g->map.addr[i][j] == '1')
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->wall.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'P')
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->P.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'C')
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->C.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'E')
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->E.p, j * I_SIZE, i * I_SIZE);
			if (!ret)
				display_err(clear_map(g->map.addr));
		}
		i++;
	}
}
