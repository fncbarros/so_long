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
/*Stupid-ass function but I'm proud of it*/
{
	static int	pe;

	if (c == 'E')
	{
		pe ^= 'E';
		if (!pe)
			return(0);
	}
	else if (c == 'P')
	{
		pe ^= 'P' << 8;
		if (!pe >> 8)
			return (0);
	}
	else if (!ft_strchr("01C", c))
		return (0);
	else if (pe == 0)
		return (1);
	return (pe);
}

static void	further_check(t_map *m)
/*Need check if theres 1+ E or P
   or just overwrite decision deleting one-a-them*/
{
	int	i;
	int	j;
	static int	pe;

	i = -1;
	while (++i < (m->columns))
	{
		j = 0;
		if (m->addr[0][i] != '1' || m->addr[m->rows - 1][i] != '1')
			display_err(clear_map(m->addr) + 1);
		while (++j < m->rows)
		{
			if (i == 0 || i == (m->columns - 1))
			{
				if (m->addr[j][i] != '1')
					display_err(clear_map(m->addr) + 1);
			}
			pe = element_control(m->addr[j][i]);
			if (!pe)
				display_err(clear_map(m->addr) + 3);
		}
	}
	if (pe != ('P' << 8) + 'E')
		display_err(clear_map(m->addr) + 3);
}

static char	**two_dimension_realloc(char ***p_arr, int size)
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
			display_err(clear_map(*p_arr));
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
Malloc'ing empty line instead of setting to NULL <----------------------- FIXIT
*/
{
	int	r;
	int	fd;

	r = 1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		display_err(0);
	while (r > 0)
	{
		m->addr = two_dimension_realloc(&m->addr, (++m->rows) + 1);
		if (m->rows == 1)
			m->columns = ft_strlen(m->addr[0]);
		r = get_next_line(fd, &m->addr[m->rows]);
		if (m->columns > 0 && r &&
			ft_strlen(m->addr[m->rows]) != (size_t)m->columns)
			r = -1;
	}
	close(fd);
	if (r == -1)
		display_err(clear_map(m->addr) + 1);
	m->rows++;
	further_check(m);
}

/*put images to window(void *mlx, void *win, t_elements *g)
	*/

void	build_map(char *m_path, t_elements *g)
{
	read_map(m_path, &g->map);//all functions do error handling

/*
	g->background.p = mlx_new_image(g->mlx, g->background.w, g->background.h);
	g->background.addr = (int *)mlx_get_data_addr(g->background.p, &g->background.bpp,
			&g->background.line, &g->background.endian);
	paint_window(&g->background, g->background.w, g->background.h);*/

	/*-------------------TMP--------------------------*/
	int i = -1;
	int total = 0;
	while (g->map.addr[++i])
	{
		printf("%s\n", g->map.addr[i]);
		total += ft_strlen(g->map.addr[i]);
	}
	printf("%d x %d == %d", g->map.columns, g->map.rows, total);
	/*-------------------TMP--------------------------*/


}


int	main(int argc, char **argv)
{
	t_elements	g;

	if (argc < 2)
		display_err(2); //DISPLAY ERROR <----------
	img_init(&g);
	build_map(argv[1], &g);


	// /*----------------TEST-------------------*/
	// 	int fd = open(argv[1], O_RDONLY);
	// 	char **line;
	// 	line = NULL;
	// 	*line = (char *)calloc(2, 10);
	// 	int r;
	// 	r = read(fd, *line, 10);
	// 	r = read(fd, *(line + 1), 10);
	// 	printf("%s\n%s\n", line[0], line[1]);
	// 	char *error = strerror(errno);
	// 	printf("%s\n", error);
	// 	free(*line);
	// 	free(line[1]);
	// 	close(fd);
	// 	exit(0);
	// /*----------------TEST-------------------*/

	clear_map(g.map.addr);
}

