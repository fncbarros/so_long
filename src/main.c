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

/*
	build keyhooks (WASD, ESC, red cross button, need free all memory in such cases)
		Actions: movement, collecting and exiting
		Requires printing images for each action
*/



int	main(int argc, char **argv)
/*RESTRUCTURE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
W_WIDTH/W_HEIGHT dependent on map and asset sizes.......*/
{
	t_elements	g;

	if (argc < 2)
		display_err(2); //DISPLAY ERROR <----------
	g_init(&g);
	g.mlx = mlx_init();
	read_map(argv[1], &g.map); //sends every image to screen
	setup_game(&g);
	g.win_p = mlx_new_window(g.mlx, g.win_w, g.win_h, "So Long");
	put_to_window(&g);
	mlx_key_hook(g.win_p, &key_press, 0); // REVIEW
    mlx_hook(g.win_p, X_BUTTON_EXIT, 0, &key_close, 0); // REVIEW

	/*___________________________________TESTING____________________________________________*/
	/*___________________________________TESTING____________________________________________*/


	mlx_loop(g.mlx);
	clear_map(g.map.addr);
	mlx_destroy_image(g.mlx, g.floor.p); /*free memory ??*/
	mlx_destroy_window(g.mlx, g.win_p); /*free memory ??*/
	// return (0);
}

