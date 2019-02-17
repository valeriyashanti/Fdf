/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asix_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 13:09:41 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/07 14:10:48 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		transorm_x(t_point *p, t_fdf *fdf)
{
	p->x_t = ((p->x * (cos(fdf->a_y) * cos(fdf->a_z))) - (p->y * \
	(cos(fdf->a_y) * sin(fdf->a_z))) + (p->z *\
	(sin(fdf->a_y)))) * (fdf->scale) + fdf->start_x;
}

void		transorm_y(t_point *p, t_fdf *fdf)
{
	p->y_t = ((p->x * (sin(fdf->a_x) * sin(fdf->a_y) * cos(fdf->a_z) + \
	cos(fdf->a_x) * sin(fdf->a_z))) + (p->y * cos(fdf->a_x)\
	* cos(fdf->a_z) - (sin(fdf->a_x) *\
	sin(fdf->a_y) * sin(fdf->a_z))) - (p->z * \
	sin(fdf->a_x) * cos(fdf->a_y))) * (fdf->scale) + fdf->start_y;
}

void		transorm_z(t_point *p, t_fdf *fdf)
{
	p->z_t = ((p->x * sin(fdf->a_x) * sin(fdf->a_z) \
	- (cos(fdf->a_x) * sin(fdf->a_y)\
	* cos(fdf->a_z))) + p->y * (cos(fdf->a_x) * sin(fdf->a_y) * sin(fdf->a_z)\
	+ sin(fdf->a_x) * cos(fdf->a_z)) + p->z * \
	(cos(fdf->a_x) * cos(fdf->a_y))) * (fdf->scale);
}

void		transformations(t_fdf *fdf)
{
	int i;
	int j;

	j = 0;
	while (fdf->matrix[j] != 0)
	{
		i = 0;
		while (fdf->matrix[j][i].index != 0)
		{
			transorm_x(&(fdf->matrix[j][i]), fdf);
			transorm_y(&(fdf->matrix[j][i]), fdf);
			transorm_z(&(fdf->matrix[j][i]), fdf);
			i++;
		}
		j++;
	}
	map_to_window(fdf);
}
