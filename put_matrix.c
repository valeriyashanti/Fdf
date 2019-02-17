/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:20:15 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 16:22:33 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_each_poin(t_fdf *fdf, int i, int j)
{
	if (fdf->matrix[j][i + 1].index != 0)
	{
		fdf->x0 = (fdf->matrix[j][i].x_t) + fdf->move_x;
		fdf->y0 = (fdf->matrix[j][i].y_t) + fdf->move_y;
		fdf->x1 = (fdf->matrix[j][i + 1].x_t) + fdf->move_x;
		fdf->y1 = (fdf->matrix[j][i + 1].y_t) + fdf->move_y;
		fdf->color = fdf->matrix[j][i].color;
		ft_putline(fdf);
	}
	if (fdf->matrix[j + 1] != NULL)
	{
		fdf->x0 = (fdf->matrix[j][i].x_t) + fdf->move_x;
		fdf->y0 = (fdf->matrix[j][i].y_t) + fdf->move_y;
		fdf->x1 = (fdf->matrix[j + 1][i].x_t) + fdf->move_x;
		fdf->y1 = (fdf->matrix[j + 1][i].y_t) + fdf->move_y;
		fdf->color = fdf->matrix[j][i].color;
		ft_putline(fdf);
	}
}

void		map_to_window(t_fdf *fdf)
{
	int i;
	int j;

	j = 0;
	while (fdf->matrix[j] != 0)
	{
		i = 0;
		while (fdf->matrix[j][i].index != 0)
		{
			ft_each_poin(fdf, i, j);
			i++;
		}
		j++;
	}
}
