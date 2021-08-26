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
{
	t_elements	g; // Declares struct for every single thing

	if (argc < 2)
		display_err(2);
	g_init(&g); // initializes image sizes to I_SIZE and everything else to 0
	g.mlx = mlx_init();
	read_map(argv[1], &g.map); // copies map to a 2d array ()
	setup_game(&g); // Builds window and images
	g.win_p = mlx_new_window(g.mlx, g.win_w, g.win_h, "So Long");
	if (!mlx_put_image_to_window(g.mlx, g.win_p, g.floor.p, 0, 0)) //painting empty space
		display_err(clear_map(g.map.addr));
	// mlx_destroy_image(g.mlx, g.floor.p); // Still not sure what this does!!
	put_to_window(&g, -1, 1); // Displays everything
    mlx_hook(g.win_p, X_BUTTON_EXIT, 0, &key_close, &g); // Segfaulting ????
	mlx_key_hook(g.win_p, &key_press, &g); // REVIEW
	// mlx_loop_hook(g.mlx, ft_render, &g); // for animation
	mlx_loop(g.mlx); // Does anything happen bellow this line ???
}

