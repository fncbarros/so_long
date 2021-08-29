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
/* l.:32 Declares struct for every single thing
l.:36 initializes image sizes to I_SIZE and everything else to 0
l.:38 copies map to a 2d array ()
l.:39 Builds window and images
l.:41 painting empty space
l.:43 Displays everything
*/
{
	t_elements	g;

	if (argc < 2)
		display_err(2);
	g_init(&g);
	g.mlx = mlx_init();
	read_map(argv[1], &g.map);
	setup_game(&g);
	//check every pointer on struct
	g.win_p = mlx_new_window(g.mlx, g.win_w, g.win_h, "So Long");
	if (!mlx_put_image_to_window(g.mlx, g.win_p, g.floor.p, 0, 0))
		display_err(clear_map(g.map.addr));
	put_to_window(&g, -1);
	mlx_hook(g.win_p, X_BUTTON_EXIT, 131072, &key_close, &g);
	mlx_key_hook(g.win_p, &key_press, &g);
	mlx_loop(g.mlx);
	return (0);
}
