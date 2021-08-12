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

int	ft_offset(int x, int y, const t_data data)
{
	return (y * data.line + x * (data.bpp / 8));
}

int	main(void/*int argc, char **argv*/)
{
	void		*mlx;
	t_object	win;
	t_data		img;
	t_object	img2;
	int			offset;

	win.w = 1920;
	win.h = 1080;


	mlx = mlx_init();
	win.p = mlx_new_window(mlx, win.w, win.h, "Window");

	img.p = mlx_new_image(mlx, win.w, win.h); /*Creating new image the same area of window*/
	img.addr = (int *)mlx_get_data_addr(img.p, &img.bpp, &img.line, &img.endian); /*getting data from image*/
	offset = ft_offset(win.w, win.h, img); /*The very last pixel in the image (or past it??)*/

//	img2.p = mlx_xpm_file_to_image(mlx, "../img/background.xmp", &img2.w, &img2.h);

	mlx_loop(mlx);
}