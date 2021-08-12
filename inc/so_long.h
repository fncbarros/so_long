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

typedef struct	s_object{
	void	*p;
	int		w;
	int		h;
}	t_object;

typedef struct	s_data{
	void	*p;
	int		*addr;
	int		bpp;
	int		line;
	int		endian;
}	t_data;


// typedef struct	s_img{
// 	void	*img;
// 	int		w;
// 	int		h;
// }	t_img;


#endif
