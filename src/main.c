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
void	display_err()
{

}
*/
char	*read_map(char *map, int *x, int *y)
/*-------------------------->LEAKING <-----------------------------
Needs error handling and adding \n maybe*/
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;

	*y = 1;
	tmp = NULL;
	fd = open(map, O_RDONLY);
	get_next_line(fd, &line);
	*x = ft_strlen(line); //might be useless
	while (get_next_line(fd, &tmp) > 0)
	{
//		line = ft_strjoin(line, "\n");
		tmp2 = line;
		line = ft_strjoin(line, tmp);
		free(tmp2);
		free(tmp);
		*y += 1;
	}
	line = ft_strjoin(line, tmp);
	free(tmp);
	// printf("%s", line);
	close(fd);
	return (line);
}

int	main(int argc, char **argv)
{/*
	void		*mlx;
	t_object	win;
	// t_data		img;
	// t_object	img2;
	t_data		img2;*/

	char	*map;
	int 	rows;
	int		columns;

	if (argc > 2)
		exit(0); //DISPLAY ERROR <--------------------
	map = read_map(argv[1], &columns, &rows);
	printf("%s\n%d\t%d\n%ld\n", map, columns, rows, ft_strlen(map));
	free (map);
	// mlx = mlx_init();
	// win.p = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "Window");

	// // img2.img.p = img_init(&img2); /*zero all data*/
	// img2.img.w = W_WIDTH;
	// img2.img.h = W_HEIGHT;
	// // img2.img.p = mlx_new_image(mlx, img2.img.w, img2.img.h); /*Creating new image the same area of window n' malloc*/
	// img2.img.p = mlx_xpm_file_to_image(mlx, "img/background.xpm", &img2.img.w, &img2.img.h);
	// img2.addr = (int *)mlx_get_data_addr(img2.img.p, &img2.bpp, &img2.line, &img2.endian); /*getting data from image but also mallocs(??)*/
	// // mlx_xpm_to_image(mlx, )
	

	// mlx_put_image_to_window(mlx, win.p, img2.img.p, 600, 400);
	// mlx_loop(mlx);
	// // mlx_destroy_image(mlx, img2.p); /*free memory ??*/
	// // mlx_destroy_window(mlx, win.p); /*free memory ??*/
}