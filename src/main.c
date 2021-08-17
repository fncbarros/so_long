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

/*Need structs or flags in order for it to be easier to free all memory in case of error*/

/*PSEUDO (or blueprint rather):
	read map
	check if it's valid
		valid chars 01CEP(only 1 P and 1 E)
		1st and last line needs be all 1's and all others need start and end w/ a 1
		total needs to be equal to no of lines * lenght of 1st line
		if not display err ("Error\n" followed by an explicit error message)
	mlx init
	build images
	build window (wall image line lenght (in pixels) * map width (in 1's))
		(paint window...)
	build map through array (1d/2d ??) (send every image to window)
	build keyhooks (WASD, ESC, red cross button, need free all memory in such cases)
		Actions: movement, collecting and exiting
		Requires printing images for each action



*/

int	main(int argc, char **argv)
/*RESTRUCTURE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
W_WIDTH/W_HEIGHT dependent on map and asset sizes.......*/
{
	t_elements	g;
	char	*map;
	int 	rows;
	int		columns;

	g.mlx = NULL;
	g.win.p = NULL;
	if (argc < 2)
		exit(0); //DISPLAY ERROR <----------
	map = read_map(argv[1], &columns, &rows);

	g.mlx = mlx_init();

	g.wall.img.p = mlx_xpm_file_to_image(g.mlx, "img/proper_wall.xpm", &g.wall.img.w, &g.wall.img.h);
	g.wall.addr = (int *)mlx_get_data_addr(g.wall.img.p, &g.wall.bpp, &g.wall.line, &g.wall.endian); /*getting data from image but also mallocs(??)*/
	g.win.w = columns * g.wall.img.w;
	g.win.h = rows * g.wall.img.h;
	g.win.p = mlx_new_window(g.mlx, g.win.w, g.win.h, "Window");
	g.background.img.w = g.win.w;
	g.background.img.h = g.win.h;

	build_map(g.mlx, map, &g); //presumably sending every image to screen
	free (map);

	mlx_put_image_to_window(g.mlx, g.win.p, g.background.img.p, 0, 0); //painting empty space

	g.character.img.p = mlx_xpm_file_to_image(g.mlx, "img/marvin.xpm", &g.character.img.w, &g.character.img.h);
	g.character.addr = (int *)mlx_get_data_addr(g.character.img.p, &g.character.bpp, &g.character.line, &g.character.endian); /*getting data from image but also mallocs(??)*/

	mlx_put_image_to_window(g.mlx, g.win.p, g.character.img.p, 600, 400);

	
	int	x = 0;
	int	y = 0;
	int i = -1;
	while (i++ < columns)
	{
		mlx_put_image_to_window(g.mlx, g.win.p, g.wall.img.p, x, y);
		x += g.wall.img.w + 1;
	}
	x = 0;
	y += g.wall.img.w;
	mlx_put_image_to_window(g.mlx, g.win.p, g.wall.img.p, x, y);
	
	mlx_loop(g.mlx);

	mlx_destroy_image(g.mlx, g.background.img.p); /*free memory ??*/
	mlx_destroy_window(g.mlx, g.win.p); /*free memory ??*/
}