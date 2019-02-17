/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:08:02 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 17:31:19 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_error(char *str)
{
	ft_putendl(str);
	exit(0);
}

int			ft_is_file(char *argv)
{
	int fd;

	fd = open(argv, O_RDONLY);
	if (read(fd, 0, 0) < 0)
		check_error("It is not a file !!!");
	close(fd);
	return (0);
}

int			ft_each_elem(char **cor, t_fdf *fdf, int i, int j)
{
	fdf->matrix[j][i].x = i - fdf->max_x / 2;
	fdf->matrix[j][i].y = j - fdf->max_y / 2;
	fdf->matrix[j][i].z = ft_atoi(cor[0]);
	fdf->matrix[j][i].color = ft_atoi_base(cor[1], 16, fdf);
	fdf->matrix[j][i].index = 1;
	return (0);
}

int			ft_line_to_matrix(t_list *map, t_fdf *fdf)
{
	int		i;
	int		j;

	j = 0;
	while (map)
	{
		fdf->list = ft_strsplit(map->content, ' ');
		i = 0;
		if (!(fdf->matrix[j] = (t_point*)malloc(sizeof(t_point) * \
		(ft_words_count(map->content, ' ') + 1))))
			exit(0);
		while (fdf->list[i])
		{
			fdf->cor = ft_strsplit(fdf->list[i], ',');
			ft_each_elem(fdf->cor, fdf, i, j);
			free(fdf->cor);
			i++;
		}
		fdf->matrix[j][i].index = 0;
		free(fdf->list);
		map = map->next;
		j++;
	}
	fdf->matrix[j] = NULL;
	return (1);
}

int			readfile(char *argv, t_fdf *fdf)
{
	int		fd;
	char	*line;
	t_list	*map;
	int		i;

	map = 0;
	i = 0;
	fd = open(argv, O_RDONLY);
	if (fd >= 0)
		while ((get_next_line(fd, &line) == 1))
		{
			fdf->tmp = ft_lstnew(line, ft_strlen(line) + 1);
			if (!(ft_push_back(&map, fdf->tmp)))
				ft_lstdel(&map, &ft_clean);
			i++;
			(fdf->max_x == 0) ? fdf->max_x = ft_words_count(line, ' ') : \
			free(line);
			if (ft_words_count(line, ' ') != fdf->max_x)
				check_error("Wrong file!");
		}
	fdf->max_y = i;
	close(fd);
	((fdf->matrix = (t_point**)malloc(sizeof(t_point*) * (i + 1)))) ? \
	ft_line_to_matrix(map, fdf) : exit(0);
	return (1);
}
