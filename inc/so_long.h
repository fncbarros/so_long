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
# include <errno.h>

# include "libft.h"
# include "get_next_line.h"

#define W_WIDTH 1920 //Both dependent on map and asset size
#define W_HEIGHT 1080

/*---------->NEED REDO STRUCTS<------------*/

/*----------PROTO--------------*/
typedef union s_creation
/*for error management purposes
	*/
{
	int		(*mlx_put_image_to_window)(void *mlx_ptr, void *win_ptr, void  *img_ptr,
				int x, int y);
	void	*(**mlx_new_image)( void *mlx_ptr, int width, int height); //???????
}	t_creation;

/*----------PROTO--------------*/

/*for images*/
typedef struct	s_data{
	void	*p;
	int		w;
	int		h;
	int		*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_data;

/*map info*/
typedef struct	s_map{
	char	**addr;
	int		rows;
	int		columns;
	int		C;
}	t_map;

/*everything*/
typedef struct	s_elements{
	void		*mlx;
	void		*win_p;
	int			win_w;
	int			win_h;
	t_map		map;
	t_data		floor;
	t_data		wall;
	t_data		P;
	t_data		C;
	t_data		E;
}	t_elements;

/*err.c*/
void	display_err(int num);
int		clear_map(char **map);
void	*malloc_n_check(size_t block, void *content, int flag);

/*utils.c*/
int		ft_offset(int x, int y, const t_data data);
void	ft_img_pixel_put(t_data *img, int color, int x, int y);
void	*g_init(t_elements *g);

/*map.c*/
void	build_map(char *m_path, t_elements *g);
void	paint_window(t_data *img, const int w, const int h);

#endif
