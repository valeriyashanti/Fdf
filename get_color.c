/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:37:21 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 16:14:42 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		create_color(t_fdf *fdf)
{
	int		i;
	int		y;

	y = 0;
	while (fdf->matrix[y])
	{
		i = 0;
		while (fdf->matrix[y][i].index != 0)
		{
			fdf->max_z = fdf->max_z / 3;
			if (fdf->matrix[y][i].z <= fdf->max_z)
				fdf->matrix[y][i].color = 0xFFFFFF;
			else if (fdf->matrix[y][i].z > fdf->max_z)
				fdf->matrix[y][i].color = 0x00ffff;
			else if (fdf->matrix[y][i].z > fdf->max_z * 2)
				fdf->matrix[y][i].color = 0xEAFDA6;
			i++;
		}
		y++;
	}
}
