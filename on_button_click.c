/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_button_click.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 11:07:37 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 16:21:02 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		key_press(t_fdf *fdf, int key)
{
	if (key == 24)
		fdf->scale += 0.5;
	if (key == 27)
		if (fdf->scale > 1)
			fdf->scale -= 0.5;
	if (key == 84)
		fdf->a_x += 0.1;
	if (key == 87)
		fdf->a_y += 0.1;
	if (key == 86)
		fdf->a_y -= 0.1;
	if (key == 83)
		fdf->a_x -= 0.1;
	if (key == 91)
		fdf->a_z += 0.1;
	if (key == 89)
		fdf->a_z -= 0.1;
	if (key == 13)
		fdf->move_y -= 5;
	if (key == 1)
		fdf->move_y += 5;
	if (key == 2)
		fdf->move_x += 5;
	if (key == 0)
		fdf->move_x -= 5;
}

int			key_iso(int key, t_fdf *fdf)
{
	if (key == 18)
	{
		fdf->projection = "PARALLEL";
		fdf->a_x = 0;
		fdf->a_y = 0;
		fdf->a_z = 0;
	}
	if (key == 19)
	{
		fdf->projection = "ISOMETRIC";
		fdf->a_y = -0.523599;
		fdf->a_x = 0.523599;
		fdf->a_z = 0;
	}
	if (key == 121)
		change_z(fdf);
	if (key == 116)
		change_z_plus(fdf);
	return (0);
}

int			deal_key(int key, t_fdf *fdf)
{
	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (key == 53)
	{
		mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
		exit(0);
	}
	key_press(fdf, key);
	key_iso(key, fdf);
	create_new_window(fdf);
	return (0);
}
