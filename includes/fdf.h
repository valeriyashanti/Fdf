/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 18:07:56 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/17 18:07:08 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "math.h"
# include "mlx.h"
# include "libft.h"
# define ABS(x) (x > 0) ? (x) : -(x)

typedef	struct	s_point
{
	int			x;
	int			y;
	int			z;
	int			color;
	int			index;
	float		x_t;
	float		y_t;
	float		z_t;
}				t_point;

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_line;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_fdf
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*line;
	t_point		**matrix;
	float		scale;
	int			iso;
	float		a_y;
	float		a_x;
	float		a_z;
	int			center_y;
	int			center_x;
	int			rotate;
	int			x0;
	int			x1;
	int			y0;
	int			y1;
	float		angle;
	int			transform;
	int			asix_x;
	int			asix_y;
	float		max_x;
	float		max_y;
	int			color;
	int			start_x;
	int			start_y;
	int			image;
	int			move_x;
	int			move_y;
	int			mouse;
	float		m_x;
	float		m_y;
	float		mp_x;
	float		mp_y;
	int			color_exist;
	float		max_z;
	char		*projection;
	double		x1_c;
	double		x0_c;
	int			delta_y;
	int			delta_x;
	int			error;
	int			error2;
	char		**cor;
	char		**list;
	t_list		*tmp;
	t_img		img;
}				t_fdf;

int				draw_line(t_fdf *fdf);
void			draw_line_y(t_fdf *fdf);
void			draw_line_x(t_fdf *fdf);
void			map_to_window(t_fdf *fdf);
void			isometric(t_fdf *fdf);
int				deal_key(int key, t_fdf *fdf);
int				readfile(char *argv, t_fdf *fdf);
int				ft_line_to_matrix(t_list *map, t_fdf *fdf);
void			check_error(char *str);
void			transform(t_fdf *fdf);
void			asix_transform(t_fdf *fdf);
void			asix(t_point *p, t_fdf *fdf);
void			transformations(t_fdf *fdf);
void			transorm_z(t_point *p, t_fdf *fdf);
void			transorm_y(t_point *p, t_fdf *fdf);
void			transorm_x(t_point *p, t_fdf *fdf);
void			ft_putline(t_fdf *fdf);
int				ft_atoi_base(char *str, int base, t_fdf *fdf);
void			ft_print(t_fdf *fdf);
int				on_mouse_press(int button, int x, int y, t_fdf *fdf);
int				on_mouse_move(int x, int y, t_fdf *fdf);
int				on_mouse_release(int button, int x, int y, t_fdf *fdf);
void			clear_and_create_window(t_fdf *fdf);
void			create_color(t_fdf *fdf);
void			put_strings(t_fdf *fdf);
void			change_z(t_fdf *fdf);
int				project(t_fdf *fdf);
void			change_z_plus(t_fdf *fdf);
void			create_new_window(t_fdf *fdf);
int				ft_is_file(char *argv);

#endif
