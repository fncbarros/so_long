/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:58:35 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/16 11:58:37 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/so_long.h"

void	paint_window(t_data *img, const int w, const int h)
/*Painting the whole window to cover asset background
4743554*/
{
	int	z;

    z = -1;
	while (++z < (w * h))
		img->addr[z] = 4743554;
}

char	*read_map(char *map, int *x, int *y)
/*-------------------------->LEAKING <-----------------------------
Stores map in char *map, no of elements in the x axis and y axis in x and y (passed by reference)
Needs error handling and adding \n maybe...but maybe not
*/
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;
	int		r;

	*y = 1;
	tmp = NULL;
	fd = open(map, O_RDONLY);
	*x = get_next_line(fd, &line); //maybe pass buffer to gnl as well cuz it's a shitty version
	// *x = ft_strlen(line); //might be useless
	r = *x;
	while ( r > 0)
	{
		 r = get_next_line(fd, &tmp);
//		line = ft_strjoin(line, "\n");
		tmp2 = strdup(line);
		free(line);
		line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		*y += 1;
		if (r == *x)
			free(tmp);
	}
	line = ft_strjoin(line, tmp);
	//  free(line);
	// printf("%s", line);
	close(fd);
	return (line);
}

/*put images to window(void *mlx, void *win, t_elements *g)
	*/

void	build_map(void *mlx, const char *map, t_elements *g)
{
	(void)map;
	g->background.img.p = mlx_new_image(mlx, g->background.img.w, g->background.img.h);
	g->background.addr = (int *)mlx_get_data_addr(g->background.img.p, &g->background.bpp, 
			&g->background.line, &g->background.endian);
	paint_window(&g->background, g->background.img.w, g->background.img.h);
}