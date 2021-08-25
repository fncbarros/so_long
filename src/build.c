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

void	paint_window(t_data *img, const int w, const int h)
/*Painting the whole window to cover asset background
4743554*/
{
	int	z;

    z = -1;
	while (++z < (w * h))
		img->addr[z] = 4743554;

}

void	setup_game(t_elements *g)
{
	g->wall.p = mlx_xpm_file_to_image(g->mlx, "img/wall.xpm", &g->wall.w, &g->wall.h);
	g->wall.addr = (int *)mlx_get_data_addr(g->wall.p, &g->wall.bpp, &g->wall.line, &g->wall.endian);
	g->win_w = g->map.columns * g->wall.w;
	g->win_h = g->map.rows * g->wall.h;
	g->floor.h = g->win_h; // ...
	g->floor.w = g->win_w; // ...
	g->floor.p = mlx_new_image(g->mlx, g->floor.w, g->floor.h);
	g->floor.addr = (int *)mlx_get_data_addr(g->floor.p, &g->floor.bpp,
			&g->floor.line, &g->floor.endian);
	paint_window(&g->floor, g->floor.w, g->floor.h);
	g->P.p = mlx_xpm_file_to_image(g->mlx, "img/Marvin.xpm", &g->P.w, &g->P.h);
	g->P.addr = (int *)mlx_get_data_addr(g->P.p, &g->P.bpp, &g->P.line, &g->P.endian);
	g->C.p = mlx_xpm_file_to_image(g->mlx, "img/petunias.xpm", &g->C.w, &g->C.h);
	g->C.addr = (int *)mlx_get_data_addr(g->C.p, &g->C.bpp, &g->C.line, &g->C.endian);
	g->E.p = mlx_xpm_file_to_image(g->mlx, "img/heart_of_gold.xpm", &g->E.w, &g->E.h);
	g->E.addr = (int *)mlx_get_data_addr(g->E.p, &g->E.bpp, &g->E.line, &g->E.endian);
	// check for NULLs
}

void	put_to_window(t_elements *g)
{
	int	i;
	int j;
	int	ret;

	ret = 1;
	i = -1;
	if (!mlx_put_image_to_window(g->mlx, g->win_p, g->floor.p, 0, 0)) //painting empty space
		display_err(clear_map(g->map.addr));
	while (++i < g->map.rows)
	{
		j = -1;
		while (++j < g->map.columns)
		{
			if (g->map.addr[i][j] == '1')
				ret = mlx_put_image_to_window(g->mlx, g->win_p, g->wall.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'P')
				ret = mlx_put_image_to_window(g->mlx, g->win_p, g->P.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'C')
				ret = mlx_put_image_to_window(g->mlx, g->win_p, g->C.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'E')
				ret = mlx_put_image_to_window(g->mlx, g->win_p, g->E.p, j * I_SIZE, i * I_SIZE);
			if (!ret)
				display_err(clear_map(g->map.addr));
		}
	}
}
