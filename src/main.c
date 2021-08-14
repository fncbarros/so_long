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
#include <stdlib.h>

int	ft_offset(int x, int y, const t_data data)
{
	return (((y * data.line) + x * (data.bpp / 8)) / 4);
}

void	ft_img_pixel_put(t_data *img, int color, int x, int y)
{
	int	*dst;

	dst = img->addr + ft_offset(x, y, *img); /*img->addr is an int *, that's why it's segfaulting*/
	*(unsigned int *)dst = color;
}

void	*img_init(t_data *img)
/*Not sure*/
{
	img->addr = NULL;
	img->bpp = 0;
	img->line = 0;
	img->endian = 0;
	img->img.w = 0;
	img->img.w = 0;
	return (NULL);
}

t_data  *create_quad(void *mlx, int color, int x, int y)
/*mallocs and creates x size square*/
{
    t_data  *quad;
    int     z;

	quad = NULL;
    quad = (t_data *)malloc(sizeof(t_data));
    quad->img.p = img_init(quad);
    quad->img.p = mlx_new_image(mlx, x, y);
    quad->addr = (int *)mlx_get_data_addr(quad->img.p, &quad->bpp, &quad->line, &quad->endian);
    z = -1;
	while (++z < (x * y))
		quad->addr[z] = color;
    return (quad);
}

void	create_rectriangle(t_data *img, int color)
/*img->img.w x img->img.h*/
{
	int	x;
	int	y;

	y = -1;
	while (++y < img->img.h)
	{
		x = -1;
		while (++x < y)
			ft_img_pixel_put(img, color, x, y);
	}
}

int	main(void/*int argc, char **argv*/)
{
	void		*mlx;
	t_object	win;
	// t_data		img;
	// t_object	img2;
	t_data		img2;


	mlx = mlx_init();
	win.p = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Window");

	img2.img.p = img_init(&img2); /*zero all data*/
	img2.img.w = W_WIDTH;
	img2.img.h = W_HEIGHT;
	// img2.img.p = mlx_new_image(mlx, img2.img.w, img2.img.h); /*Creating new image the same area of window n' malloc*/
	img2.img.p = mlx_xpm_file_to_image(mlx, "img/background.xpm", &img2.img.w, &img2.img.h);
	img2.addr = (int *)mlx_get_data_addr(img2.img.p, &img2.bpp, &img2.line, &img2.endian); /*getting data from image but also mallocs(??)*/
	// mlx_xpm_to_image(mlx, )
	

	mlx_put_image_to_window(mlx, win.p, img2.img.p, 600, 400);
	mlx_loop(mlx);
	// mlx_destroy_image(mlx, img2.p); /*free memory ??*/
	// mlx_destroy_window(mlx, win.p); /*free memory ??*/
}