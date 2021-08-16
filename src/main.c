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
	g.collect.img.p = mlx_xpm_file_to_image(mlx, "img/walls.xpm", &g.collect.img.w, &g.collect.img.h);
	g.collect.addr = (int *)mlx_get_data_addr(g.collect.img.p, &g.collect.bpp, &g.collect.line, &g.collect.endian); /*getting data from image but also mallocs(??)*/	

	mlx_put_image_to_window(mlx, win.p, g.character.img.p, 600, 400);
	mlx_put_image_to_window(mlx, win.p, g.collect.img.p, 1200, 800);
	mlx_loop(mlx);

	mlx_destroy_image(mlx, g.background.img.p); /*free memory ??*/
	mlx_destroy_window(mlx, win.p); /*free memory ??*/
}