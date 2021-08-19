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

int	read_map(char *map, t_map *m)
/*-------------------------->LEAKING! REMAKE IT!! <-----------------------------
Stores map in char *map, no of elements in the x axis and y axis in x and y (passed by reference)
Needs error handling and adding \n maybe...but maybe not
*/
{
	int	r;
	int	fd;

	m->rows = -1;
	r = 1;

	fd = open(map, O_RDONLY);
	while (++m->rows && r > 0)
	{
		if (m->rows == 1)
			m->columns = ft_strlen(m->addr[0]);
		r = get_next_line(fd, &m->addr[m->rows]);
		if (r > 0 && ft_strlen(m->addr[m->rows]) != m->columns)
			r = -1;
	}
	if (r == -1)
		return (clear_map(m->addr));
	m->addr[m->rows] = 0;
	return (m->rows--);
}

/*put images to window(void *mlx, void *win, t_elements *g)
	*/

void	build_map(char *m_path, t_elements *g)
{
	int	i;

	i = 0;
	while (g->map.addr[i] != NULL)
		g->map.addr[i] = read_map(m_path, &g->map);




	g->background.p = mlx_new_image(g->mlx, g->background.w, g->background.h);
	g->background.addr = (int *)mlx_get_data_addr(g->background.p, &g->background.bpp,
			&g->background.line, &g->background.endian);
	paint_window(&g->background, g->background.w, g->background.h);
}

/*
int	main(int argc, char **argv)
{
	if (argc < 2)
		exit(0); //DISPLAY ERROR <----------
	char *map = read_map(argv[1], &columns, &rows);
	printf("%s\n", map);
}
*/

/*
	char	*read_map(char *map, int *x, int *y)

	int		fd;
	char	*line;
	char	*tmp;
	char	*tmp2;
	int		r;

	*y = 1;
	tmp = NULL;
	fd = open(map, O_RDONLY);
	if ( 1 > get_next_line(fd, &line))
		return (NULL);
	*x = ft_strlen(line);
	r = *x;
	while ( r > 0)
	{
		 r = get_next_line(fd, &tmp);
//		line = ft_strjoin(line, "\n");
		tmp2 = strdup(line);
		free(line);
		line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		*y += 1;
		if (r == *x)
			free(tmp);
	}
	line = ft_strjoin(line, tmp);
	//  free(line);
	// printf("%s", line);
	close(fd);
	return (line);*/
