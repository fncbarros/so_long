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
/*"Paints" new image with single color*/
{
	int	z;

	z = -1;
	while (++z < (w * h))
		img->addr[z] = color;
}

void	setup_game(t_elements *g)
/*Need to remake floor, not the best aproach
(l.:31-32) -Sets window size taking img sizes into account (all imgs I_SIZE x 			I_SIZE squares);
(l.:33-38) -Creates a window sized matte floor of color defined by Macro FLOOR;
(l.:39-54) -Fetches imgs from img/ folder and "builds" them;
*/
{
	g->win_w = g->map.columns * I_SIZE;
	g->win_h = g->map.rows * I_SIZE;
	g->floor.h = g->win_h;
	g->floor.w = g->win_w;
	g->floor.p = mlx_new_image(g->mlx, g->floor.w, g->floor.h);
	g->floor.addr = (int *)mlx_get_data_addr(g->floor.p,
			&g->floor.bpp, &g->floor.line, &g->floor.endian);
	paint_floor(&g->floor, g->floor.w, g->floor.h, FLOOR);
	g->wall.p = mlx_xpm_file_to_image(g->mlx,
			"img/wall.xpm", &g->wall.w, &g->wall.h);
	g->wall.addr = (int *)mlx_get_data_addr(g->wall.p, &g->wall.bpp,
			&g->wall.line, &g->wall.endian);
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

// static void	*new_floor(t_elements *g)
// /*REMAKE: New img pointer I_SIZE x I_SIZE for "patching up" floor or
// 	Rebuild everything everytime there's a change*/
// {
// 	t_data	tmp;

// 	tmp.p = mlx_new_image(g->mlx, I_SIZE, I_SIZE);
// 	tmp.addr = (int *)mlx_get_data_addr(tmp.p,
// 			&tmp.bpp, &tmp.line, &tmp.endian);
// 	paint_floor(&tmp, I_SIZE, I_SIZE, FLOOR);
// 	g->floor.h = I_SIZE;
// 	g->floor.w = I_SIZE;
// 	g->floor.addr = tmp.addr;
// 	g->floor.line = tmp.line;
// 	return (tmp.p);
// }

int	put_to_window(t_elements *g, int i, int ret)
/*Scans map and displays every object. It should run everytime there's a specific event
	i decides which line ro start printing from*/
{
	int	j;

	while (++i < g->map.rows)
	{
		j = -1;
		while (++j < g->map.columns)
		{
			if (g->map.addr[i][j] == '1')
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->wall.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'P')
			{
				// if (g->map.C < 0)
				// 	ret = mlx_put_image_to_window(g->mlx,
				// 			g->win_p, g->E.p, j * I_SIZE, i * I_SIZE);
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->P.p, j * I_SIZE, i * I_SIZE);
			}
			else if (g->map.addr[i][j] == 'C')
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->C.p, j * I_SIZE, i * I_SIZE);
			else if (g->map.addr[i][j] == 'E')
			{
				ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->E.p, j * I_SIZE, i * I_SIZE);
				if (g->map.Px == j && g->map.Py == i)
					ret = mlx_put_image_to_window(g->mlx,
						g->win_p, g->P.p, j * I_SIZE, i * I_SIZE);
			}
			// if (!ret)
				// display_err(clear_map(g->map.addr));
		}
	}
	return (ret);
}
