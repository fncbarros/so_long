/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbarros <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 11:58:35 by fbarros           #+#    #+#             */
/*   Updated: 2021/08/16 11:58:37 by fbarros          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	element_control(char c)
/*Very sloppy implementation but the intention was good.
 So this serves as an auxiliary to the map scanning function, returning one of three values:
 	- A number less than 69 (ascii for E) in case it detects a certain failure (if there's more than one P or E element 
	or anything else than "01PCE")". In such case it will return the error id (see display_err() in err.c);
	- pe in case if finds an 'E' or 'P' element for the first time. pe should be equal to
	the bit representation of 'P' followed by 'E' (hence the name) once the map(see "parent" function)
	has been totally scanned.
	I use an '^' or XOR operand to make sure there's no more, no less than one instance of both chars.
*/
{
	static int	pe;

	if (c == 'E')
	{
		pe ^= 'E';
		if (!pe)
			return(3);
	}
	else if (c == 'P')
	{
		pe ^= 'P' << 8;
		if (!pe >> 8)
			return (3);
	}
	else if (!ft_strchr("01C", c))
		return (6);
	else if (pe == 0)
		return ('E');
	return (pe);
}

static void	further_check(t_map *m)
/*Overwrite > 1 'E' or 'P' deleting one-a-them ???
	Accept lower case elements ?? (toupper)
 Checks if map is rectangular and outterbounds are filled with 1's.*/
{
	int	i;
	int	j;
	static int	pe;

	i = -1;
	while (++i < (m->columns))
	{
		j = 0;
		if (m->addr[0][i] != '1' || m->addr[m->rows - 1][i] != '1')
			display_err(clear_map(m->addr) + 5);
		while (++j < m->rows)
		{
			if (i == 0 || i == (m->columns - 1))
			{
				if (m->addr[j][i] != '1')
					display_err(clear_map(m->addr) + 5);
			}
			pe = element_control(m->addr[j][i]);
			if (pe < 69)
				display_err(clear_map(m->addr) + pe);
		}
	}
	if (pe != ('P' << 8) + 'E')
		display_err(clear_map(m->addr) + 3);
}

static char	**two_dimension_realloc(char ***p_arr, int size)
/*Allways sets last double pointer to NULL*/
{
	char	**tmp;
	char	**tmp2;
	int		i;

	i = -1;
	tmp2 = *p_arr;
	tmp = ft_calloc(size + 1, sizeof(char **));
	tmp[size] = NULL;
	if (size > 1)
	{
		if (!tmp)
			display_err(clear_map(*p_arr) + 1);
		while (tmp2[++i] && i < size)
			tmp[i] = tmp2[i];
		tmp[i] = NULL;
		free(*p_arr);
	}
	else if (!tmp)
		display_err(1);
	return (tmp);
}

static void	read_map(char *map, t_map *m)
/*Stores map in 2d array char **addr; reallocs (sorta)
All functions handle errors
Malloc'ing empty line instead of setting to NULL <----------------------- FIXIT!!!!!!
*/
{
	int	r;
	int	fd;

	r = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		display_err(1);
	while (r > 0)
	{
		m->addr = two_dimension_realloc(&m->addr, (++m->rows) + 1);
		if (m->rows == 1)
			m->columns = ft_strlen(m->addr[0]);
		r = get_next_line(fd, &m->addr[m->rows]);
		if (m->columns > 0 && r &&
			ft_strlen(m->addr[m->rows]) != (size_t)m->columns)
			r = -4;
	}
	close(fd);
	if (r < 0)
		display_err(clear_map(m->addr) + (r * -1));
	m->rows++;
	further_check(m);
}

/*put images to window(void *mlx, void *win, t_elements *g)
					or
init_images(t_elements *g)*/

void	build_map(char *m_path, t_elements *g)
/*Need to check mlx returns*/
{
	read_map(m_path, &g->map); //might leave the calling to main because window
	g->wall.p = mlx_xpm_file_to_image(g->mlx, "img/proper_wall.xpm", &g->wall.w, &g->wall.h);	
	g->wall.addr = (int *)mlx_get_data_addr(g->wall.p, &g->wall.bpp, &g->wall.line, &g->wall.endian);
	// g->P.p = mlx_xpm_file_to_image(g->mlx, "img/marvin.xpm", &g->P.w, &g->P.h);
	// g->P.addr = (int *)mlx_get_data_addr(g->P.p, &g->P.bpp, &g->P.line, &g->P.endian);
	// g->E.p = mlx_xpm_file_to_image(g->mlx, "img/ whatevs .xpm", &g->E.w, &g->E.h);
	// g->E.addr = (int *)mlx_get_data_addr(g->E.p, &g->E.bpp, &g->E.line, &g->E.endian);
	// g->C.p = mlx_xpm_file_to_image(g->mlx, "img/ ... .xpm", &g->C.w, &g->C.h);
	// g->C.addr = (int *)mlx_get_data_addr(g->C.p, &g->C.bpp, &g->C.line, &g->C.endian);
	// check if any returned NULL ??

	/*          background              */
	g->win_w = g->map.columns * g->wall.w;
	g->win_h = g->map.rows * g->wall.h;
	g->floor.h = g->win_h; // ...
	g->floor.w = g->win_w; // ...
	g->floor.p = mlx_new_image(g->mlx, g->floor.w, g->floor.h);
	g->floor.addr = (int *)mlx_get_data_addr(g->floor.p, &g->floor.bpp,
			&g->floor.line, &g->floor.endian);
	paint_window(&g->floor, g->floor.w, g->floor.h);
	/*          background              */


	/*          walls              */
	int	i;

	i = 0;
	while (g->map.addr)


	/*          walls              */

}

// int	main(int argc, char **argv)
// {
// 	t_elements	g;

// 	if (argc < 2)
// 		display_err(2); //DISPLAY ERROR <----------
// 	img_init(&g);
// 	build_map(argv[1], &g);
// 	clear_map(g.map.addr);
// }


	/*-------------------TMP--------------------------*/
	// int i = -1;
	// int total = 0;
	// while (g->map.addr[++i])
	// {
	// 	printf("%s\n", g->map.addr[i]);
	// 	total += ft_strlen(g->map.addr[i]);
	// }
	// printf("%d x %d == %d", g->map.columns, g->map.rows, total);
	/*-------------------TMP--------------------------*/