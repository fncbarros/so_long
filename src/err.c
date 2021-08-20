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

void	*malloc_n_check(size_t block, void *content)
{
	void	*p;

     (void)content;
	p = malloc(block);
    // *p = content; //memcpy ??
	if (!p)
		display_err(errno);
    return (p);
}

void	display_err(int num)

{
    if (errno)
        perror(strerror(errno));
    else if (num == 1)
        ft_putstr_fd("Failed to read map.\n", 2);
    else if (num == 2)
        ft_putstr_fd("Missing *.ber file.\n", 2);
    // exit(1);
}
/*
void    err_check(void *element)
{
    if (element == NULL)
        display_err(something...)
}
*/
int    clear_map(char **map)
{
    if (*map)
    {
        while (*map)
            free(*map++);
    }
    return(0);
}