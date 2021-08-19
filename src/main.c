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
		total needs be = columns x rows
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

	alloc for map only

*/

int	main(int argc, char **argv)
/*RESTRUCTURE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
W_WIDTH/W_HEIGHT dependent on map and asset sizes.......*/
{
	t_elements	g;

	if (argc < 2)
		exit(0); //DISPLAY ERROR <----------
	g.mlx = mlx_init();

	if (!read_map(argv[1], &g.map))
		return (0); //DISPLAY ERROR
	// build_map(argv[1], &g); //presumably sending every image to screen


	// g.wall.p = mlx_xpm_file_to_image(g.mlx, "img/proper_wall.xpm", &g.wall.w, &g.wall.h);
	// g.wall.addr = (int *)mlx_get_data_addr(g.wall.p, &g.wall.bpp, &g.wall.
	// line, &g.wall.endian); /*getting data from image but also mallocs(??)*/
	// //if !g.wall.addr ...
	// g.win_w = g.map.columns * g.wall.w;
	// g.win_h = g.map.rows * g.wall.h;
	// g.win_p = mlx_new_window(g.mlx, g.win_w, g.win_h, "So Long");
	// g.background.w = g.win_w;
	// g.background.h = g.win_h;



	// mlx_put_image_to_window(g.mlx, g.win_p, g.background.p, 0, 0); //painting empty space

	// g.character.p = mlx_xpm_file_to_image(g.mlx, "img/marvin.xpm", &g.character.w, &g.character.h);
	// g.character.addr = (int *)mlx_get_data_addr(g.character.p, &g.character.bpp, &g.character.line, &g.character.endian); /*getting data from image but also mallocs(??)*/

	// mlx_put_image_to_window(g.mlx, g.win_p, g.character.p, 600, 400);

	// int	x = 0;
	// int	y = 0;
	// int i = -1;
	// while (i++ < g.map.columns)
	// {
	// 	mlx_put_image_to_window(g.mlx, g.win_p, g.wall.p, x, y);
	// 	x += g.wall.w + 1;
	// }
	// x = 0;
	// y += g.wall.w;
	// mlx_put_image_to_window(g.mlx, g.win_p, g.wall.p, x, y);

	// mlx_loop(g.mlx);
	// free (g.map.addr); //free_map(g.map.addr)
	// mlx_destroy_image(g.mlx, g.background.p); /*free memory ??*/
	// mlx_destroy_window(g.mlx, g.win_p); /*free memory ??*/
}
