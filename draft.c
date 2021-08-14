/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:24:46 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/14 17:46:10 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/so_long.h"

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

void	create_simple_pattern(t_data *img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < W_HEIGHT)
	{
		x = -1;
		while (++x < W_WIDTH)
		{
			if (x % 2 == 0)
				// img->addr[ft_offset(x, y, *img)] = 0xff0000;
				ft_img_pixel_put(img, 0xff0000, x, y);
			else
				// img->addr[ft_offset(x, y, *img)] = 0xffffff;
				ft_img_pixel_put(img, 0xffffff, x, y);
		}
	}
}

void	create_square(t_data *img, int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < img->img.h)
	{
		x = -1;
		while (++x <= img->img.h)
			ft_img_pixel_put(img, color, x, y);
	}
}

void	create_rectriangle(t_data *img, int color)
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

int	main(void/*int argc, char **argv*/)
{
	void		*mlx;
	t_object	win;
	// t_data		img;
	// t_object	img2;
	t_data		img2;
	int			offset;

	img2.img.p = img_init(&img2); /*zero all data*/

	mlx = mlx_init();
	win.p = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Window");

	img2.img.w = 500;
	img2.img.h = 500;
	img2.img.p = mlx_new_image(mlx, img2.img.w, img2.img.h); /*Creating new image the same area of window n' malloc*/
	img2.addr = (int *)mlx_get_data_addr(img2.img.p, &img2.bpp, &img2.line, &img2.endian); /*getting data from image but also mallocs(??)*/
	/*bpp = 32 (bits), line = image width * 4 (in bytes), endian = 0*/
	// printf("%d, %d, %d", img2.bpp, img2.line, img2.endian);
	create_square(&img2, 0xff00ff);
	create_rectriangle(&img2, 0x7f00ffff);

	// img2.p = mlx_xpm_file_to_image(mlx, "../img/parallax-space-big-planet_1.xpm", &img2.w, &img2.h); /*malloc?*/
	// img2.addr = (int *)mlx_get_data_addr(img2.p, &img2.bpp, &img2.line, &img2.endian); /*getting data from image*/
	offset = ft_offset(960, 540, img2); /*The very last pixel in the image (or past it??)*/
	// printf("%d\n", offset);
	// ft_img_pixel_put(&img2, 0xffffff, 960, 540);
	// img2.addr[(img2.line / 2) / 4 + ((img2.line / 4) * (W_HEIGHT / 2))] = 0xff0000; /*Exact center of image*/
	// img2.addr[1037760] = 0xff0000; /*Exact center of image*/
	// printf("%d + %d = %d\noffset = %d", (img2.line / 2) / 4, (img2.line / 4) * (W_HEIGHT / 2), (img2.line / 2) / 4 + ((img2.line / 4) * (W_HEIGHT / 2)), offset);
	// printf("%d = %d", (img2.line / 2) / 4, W_WIDTH / 2);

	mlx_put_image_to_window(mlx, win.p, img2.img.p, W_WIDTH / 3, W_HEIGHT / 3);
	mlx_loop(mlx);
	// mlx_destroy_image(mlx, img2.p); /*free memory ??*/
	// mlx_destroy_window(mlx, win.p); /*free memory ??*/
}
