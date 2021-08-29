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
