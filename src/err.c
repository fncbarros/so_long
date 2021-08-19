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

/*perror(strerror(int enum));
    perror("Error");
*/

void	*malloc_n_check(size_t block, void *element)
{
	void	*p;

    (void)element;
	p = malloc(block);
	if (!p)
		display_err();
    return (p);
}

void	display_err()
{
    exit(1);
}

void    err_check(void *element)
{
    if (element == NULL)
        display_err(something...)
}

int    clear_map(char **map)
{
    while (*map)
        free(*map++);
}
