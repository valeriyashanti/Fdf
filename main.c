/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 16:07:47 by gkessler          #+#    #+#             */
/*   Updated: 2019/02/02 16:38:52 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		get_params(t_fdf *fdf)
{
	fdf->a_x = 0;
	fdf->a_y = 0;
	fdf->a_z = 0;
	fdf->scale = 1200 / sqrt(fdf->max_x * fdf->max_x + \
	fdf->max_x * fdf->max_x) - 0.6;
	fdf->start_x = 1000;
	fdf->start_y = 600;
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, 2000, 1200);
	fdf->img.data = (int*)mlx_get_data_addr(fdf->img.img_ptr, \
	&fdf->img.bpp, &fdf->img.size_line, &fdf->img.endian);
	fdf->move_y = 0;
	fdf->move_x = 0;
	fdf->mouse = 0;
	fdf->mp_x = 0;
	fdf->m_x = 0;
	fdf->mp_y = 0;
	fdf->m_y = 0;
	fdf->max_z = 0;
	fdf->projection = "PARALLEL";
	fdf->color = 0;
	if (fdf->color_exist == 0)
		create_color(fdf);
}

int				main(int argc, char **argv)
{
	t_fdf	*fdf;

	if (argc == 2)
	{
		if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
			return (0);
		ft_is_file(argv[1]);
		readfile(argv[1], fdf);
		fdf->mlx_ptr = mlx_init();
		fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, 2000, 1200, "mlx 42");
		get_params(fdf);
		transformations(fdf);
		mlx_put_image_to_window(fdf->mlx_ptr, \
		fdf->win_ptr, fdf->img.img_ptr, 0, 0);
		put_strings(fdf);
		mlx_hook(fdf->win_ptr, 2, 0, deal_key, fdf);
		mlx_hook(fdf->win_ptr, 4, 0, on_mouse_press, fdf);
		mlx_hook(fdf->win_ptr, 5, 0, on_mouse_release, fdf);
		mlx_hook(fdf->win_ptr, 6, 0, on_mouse_move, fdf);
		mlx_loop(fdf);
		free(fdf);
	}
	else
		(argc > 2) ? check_error("Error") : check_error("No file appeared!");
	return (0);
}
