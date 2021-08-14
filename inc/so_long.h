/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 17:53:17 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/11 18:29:35 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <string.h>
# include <mlx.h>

//# include "libft.h"

#define W_WIDTH 1920
#define W_HEIGHT 1080

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

int		ft_offset(int x, int y, const t_data data);
void	ft_img_pixel_put(t_data *img, int color, int x, int y);
/*Both set to deal with int * addresses*/


#endif
