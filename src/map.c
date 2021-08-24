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

void	read_map(char *map, t_map *m)
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


// static void	img_position(t_elements *g, char element, int x, int y)
// {
// 	void	*img;

// 	if (element == '1')
// 		img = g->wall.p;
// 	if (element == 'P')
// 		img = g->P.p;
// 	if (element == 'E')
// 		img = g->E.p;
// 	if (element == 'C')
// 		img = g->C.p;

// 	//need calculate offset ---> MACRO
// 	if (!mlx_put_image_to_window(g->mlx, g->win_p, img, x, y))
// 		display_err(clear_map(g->map.addr)); //Not sure about err checking
// }
void	build_map(char *m_path, t_elements *g)
/*Need to check mlx returns*/
{
	// int	i;
	// int	j;
	
	read_map(m_path, &g->map); //might leave the calling to main because window
	
	// setup_game(g);




	// setup_game(g);
	// i = -1;
	// while (g->map.addr[++i])
	// {
	// 	j = -1;
	// 	while (++j < g->map.columns /*g->map.addr[i][j]*/)
	// 	{
	// 		if (g->map.addr[i][j] == '0')
	// 			j++;
	// 		if (j < g->map.columns)
	// 		{
	// 			img_position(g, g->map.addr[i][j], j, i); //not sure about j and i
	// 		}
	// 	}
	// 	// i++;
	// 	//g->map.
	// }
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
