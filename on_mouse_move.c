/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_mouse_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 16:20:45 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 16:21:00 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			on_mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (x >= 0 && x <= 2000 && y >= 0 && y <= 1200)
	{
		if (button == 1)
		{
			fdf->mouse = 1;
			fdf->m_x = x;
			fdf->m_y = y;
		}
		if (button == 5)
			fdf->scale -= 0.5;
		if (button == 4 && fdf->scale != 0)
			fdf->scale += 0.5;
		if (button == 4 || button == 5)
			create_new_window(fdf);
	}
	return (0);
}

int			on_mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)button;
	(void)x;
	(void)y;
	fdf->mouse = 0;
	return (0);
}

int			on_mouse_move(int x, int y, t_fdf *fdf)
{
	if (x >= 0 && x <= 2000 && y >= 0 && y <= 1200)
	{
		fdf->mp_x = fdf->m_x;
		fdf->mp_y = fdf->m_y;
		fdf->m_x = x;
		fdf->m_y = y;
		if (fdf->mouse == 1)
		{
			fdf->a_x += (fdf->mp_y - y) / 150;
			fdf->a_y -= (fdf->mp_x - x) / 150;
		}
		if (fdf->mouse == 1)
			create_new_window(fdf);
	}
	return (0);
}
