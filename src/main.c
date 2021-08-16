/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:24:46 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/11 18:52:38 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"



int	main(int argc, char **argv)
/*W_WIDTH/W_HEIGHT dependent on map and asset sizes.......*/
{
	void		*mlx;
	t_object	win;
	t_elements	g;

	// (void)argc;
	// (void)argv;
	char	*map;
	int 	rows;
	int		columns;

	mlx = NULL;
	win.p = NULL;
	if (argc < 2)
		exit(0); //DISPLAY ERROR <----------
	map = read_map(argv[1], &columns, &rows);
	g.background.img.w = W_WIDTH;
	g.background.img.h = W_HEIGHT;

	mlx = mlx_init();
	win.p = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Window");

	build_map(mlx, map, &g);
	free (map);

	mlx_put_image_to_window(mlx, win.p, g.background.img.p, 0, 0);

	g.character.img.w = W_WIDTH;
	g.character.img.h = W_HEIGHT;
	g.character.img.p = mlx_xpm_file_to_image(mlx, "img/marvin.xpm", &g.character.img.w, &g.character.img.h);
	g.character.addr = (int *)mlx_get_data_addr(g.character.img.p, &g.character.bpp, &g.character.line, &g.character.endian); /*getting data from image but also mallocs(??)*/	

	mlx_put_image_to_window(mlx, win.p, g.character.img.p, 600, 400);
	mlx_loop(mlx);

	mlx_destroy_image(mlx, g.background.img.p); /*free memory ??*/
	mlx_destroy_window(mlx, win.p); /*free memory ??*/
}