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

/*All images set to I_SIZE x I_SIZE*/
# define I_SIZE 150
# define FLOOR 4743554

/*key hooks*/
# define KEY_PRESS 2 //keyboard events
# define KEY_ESC 53
# define X_BUTTON_EXIT 17 //mouse close
# define UP 13
# define DOWN 1
# define LEFT 0
# define RIGHT 2

/*for images*/
typedef struct s_data{
	void	*p;
	int		w;
	int		h;
	int		*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_data;

/*map info
Px and Py are 'P'coordinates*/
typedef struct s_map{
	char	**addr;
	int		rows;
	int		columns;
	int		C;
	int		Px;
	int		Py;
}	t_map;

/*everything*/
typedef struct s_elements{
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
void	read_map(char *map, t_map *m);

/*build.c*/
void	setup_game(t_elements *g);
void	put_to_window(t_elements *g, int i, int ret);

/*events.c*/
int		key_close(int key, t_elements *g); //red window button
int		key_press(int key, t_elements *g); // prints keys on screen

#endif
