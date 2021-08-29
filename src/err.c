/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 12:58:15 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/16 12:58:18 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

/*
maybe somethn like check(mlx_put_image...) for failure checking

void or int check(int i, t_elements *g)
{
    if (!i)
    {
        clear_everything;
        exit
    }
}
*/

void	*malloc_n_check(size_t block, void *content, int flag)
/*Not sure if useful
flag in case there's memory to free*/
{
	void	*p;

	p = ft_calloc(1, block);
	if (!p)
	{
		if (flag)
			return (NULL);
		else
			display_err(0);
	}
	if (content)
		ft_memcpy(p, content, block);
	return (p);
}

void	display_err(int num)

{
	ft_putstr_fd("Error\n", 2);
	if (errno)
		perror(strerror(errno));
	if (num == 1)
		ft_putstr_fd("Failed to read map.\n", 2);
	else if (num == 2)
		ft_putstr_fd("Missing *.ber file.\n", 2);
	else if (num == 3)
		ft_putstr_fd("Wrong number of 'P','E' and/or 'C' elements in map.\n", 2);
	else if (num == 4)
		ft_putstr_fd("Map is not rectangular.\n", 2);
	else if (num == 5)
		ft_putstr_fd("All map outter elements need to be '1'.\n", 2);
	else if (num == 6)
		ft_putstr_fd("Accepted map characters: \"01PCE\".\n", 2);
	exit(1);
}

int	clear_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
	return (0);
}
