/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 15:39:21 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/15 15:53:01 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include <unistd.h>
# include <stdlib.h>
#include "libft.h"

int		get_next_line(int fd, char **line);
int		ft_tmp_update(char **tmp, char **buf, ssize_t r, char **line);
int		ft_line_ret(char **tmp, char **line);
int		ft_final(char **line, char **tmp);
int		ft_err(char **buf, char **tmp, char **line, int i);

#endif
