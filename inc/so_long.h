/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:53:17 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/15 15:39:00 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <mlx.h>
# include <fcntl.h>

# include "libft.h"
# include "get_next_line.h"

#define W_WIDTH 1920 //Both dependent on map and asset size
#define W_HEIGHT 1080

/*---------->NEED REDO STRUCTS<------------*/

typedef struct	s_object{
	void	*p;
	int		w;
	int		h;
}	t_object;

typedef struct	s_data{
	t_object	img;
	int			*addr;
	int			bpp;
	int			line;
	int			endian; /*bool n' cast?*/
}	t_data;

typedef struct	s_elements{
	t_data	background;
	t_data	wall; //??
	t_data	character;
	t_data	collect;
	//...
}	t_elements;

int		ft_offset(int x, int y, const t_data data);
void	ft_img_pixel_put(t_data *img, int color, int x, int y);
/*Both set to deal with int * addresses*/
void	*img_init(t_data *img);

char	*read_map(char *map, int *x, int *y);
void	build_map(void *mlx, const char *map, t_elements *g);
void	paint_window(t_data *img, const int w, const int h);

#endif
