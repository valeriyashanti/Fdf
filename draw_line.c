/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:16:12 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/02 20:39:18 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_strings(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, \
	5, 0x9370DB, ft_strjoin("X - ", ft_itoa(fdf->x0)));
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 100, 5, \
	0x9370DB, ft_strjoin("Y - ", ft_itoa(fdf->y0)));
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 30, \
	0x00FFFF, ft_strjoin("Pr - ", fdf->projection));
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 300, 5, \
	0x9370DB, ("To change size use - and + or mouse roll"));
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 300, 30, \
	0x00FFFF, "To transform map press left mouse button and move it");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 900, 30, \
	0x00FFFF, "To change projections use 1 and 2 buttons");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 900, 5, \
	0x9370DB, "To transorm with buttons use \
	124578 on the right side of a keyboard");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 55, \
	0x9370DB, "To move figure agound use A-S-D-W buttons");
}

void		ft_putline(t_fdf *fdf)
{
	int			sign_x;
	int			sign_y;

	sign_x = (fdf->x0 < fdf->x1) ? 1 : -1;
	sign_y = (fdf->y0 < fdf->y1) ? 1 : -1;
	fdf->delta_x = ABS(fdf->x1 - fdf->x0);
	fdf->delta_y = ABS(fdf->y1 - fdf->y0);
	fdf->error = fdf->delta_x - fdf->delta_y;
	while (fdf->x0 != fdf->x1 || fdf->y0 != fdf->y1)
	{
		if ((int)fdf->y0 >= 0 && (int)fdf->y0 < 1200 \
		&& (int)fdf->x0 >= 0 && (int)fdf->x0 <= 2000)
			fdf->img.data[fdf->y0 * 2000 + fdf->x0] = fdf->color;
		fdf->error2 = fdf->error * 2;
		if (fdf->error2 > -fdf->delta_y)
		{
			fdf->error -= fdf->delta_y;
			fdf->x0 += sign_x;
		}
		if (fdf->error2 < fdf->delta_x)
		{
			fdf->error += fdf->delta_x;
			fdf->y0 += sign_y;
		}
	}
}
