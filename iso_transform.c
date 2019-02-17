/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso_transform.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 12:22:08 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 16:15:45 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		change_z(t_fdf *fdf)
{
	int j;
	int i;

	j = 0;
	while (fdf->matrix[j] != 0)
	{
		i = 0;
		while (fdf->matrix[j][i].index != 0)
		{
			fdf->matrix[j][i].z -= 1;
			i++;
		}
		j++;
	}
}

void		change_z_plus(t_fdf *fdf)
{
	int j;
	int i;

	j = 0;
	while (fdf->matrix[j] != 0)
	{
		i = 0;
		while (fdf->matrix[j][i].index != 0)
		{
			fdf->matrix[j][i].z += 1;
			i++;
		}
		j++;
	}
}
