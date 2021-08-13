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

ft_img_pixel_put(t_data *img, int color, int x, int y)
{
	int	*dst;

	dst = img->addr + ft_offset(x, y, *img);
	*(unsigned int *)dst = color;
}

void	*img_init(t_data *img)
/*Not sure*/
{
	img->addr = NULL;
	img->bpp = 0;
	img->line = 0;
	img->endian = 0;
	img->w = 0;
	img->h = 0;
	return (NULL);
}

int	main(void/*int argc, char **argv*/)
{
	void		*mlx;
	t_object	win;
//	t_data		img;
//	t_object	img2;
	t_data		img2;
	int			offset;

	win.w = 1920;
	win.h = 1080;
	img2.p = img_init(&img2);

	mlx = mlx_init();
	win.p = mlx_new_window(mlx, win.w, win.h, "Window");

	img2.p = mlx_new_image(mlx, win.w, win.h); /*Creating new image the same area of window*/
	img2.addr = (int *)mlx_get_data_addr(img2.p, &img2.bpp, &img2.line, &img2.endian); /*getting data from image*/

//	img2.addr = (int *)mlx_get_data_addr(img.p, &img.bpp, &img.line, &img.endian); /*getting data from image*/
	img2.p = mlx_xpm_file_to_image(mlx, "../img/background.xmp", &img2.w, &img2.h);
	offset = ft_offset(img2.w, img2.h, img2); /*The very last pixel in the image (or past it??)*/
	mlx_put_image_to_window(mlx, win.p, img2.p, img2.w, img2.h);

	mlx_loop(mlx);
}