/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <gkessler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:46:25 by gkessler          #+#    #+#             */
/*   Updated: 2019/01/06 16:53:19 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	int			is_spaces(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\r' || c == '\f')
		return (1);
	return (0);
}

static	int			is_base(int c, int base)
{
	char	*str;
	char	*str_up;
	int		i;

	str = "0123456789abcdef";
	str_up = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (c == str[i] || c == str_up[i])
			return (i);
		i++;
	}
	return (-1);
}

int					ft_atoi_base(char *str, int base, t_fdf *fdf)
{
	int i;
	int n;
	int ng;

	i = 0;
	n = 0;
	ng = 0;
	if (str == NULL)
		return (0xffffff);
	while (is_spaces(str[i]))
		i++;
	if (str[i] == '0' && str[i + 1] == 'x')
		i += 2;
	while (is_base(str[i], base) != -1)
	{
		n = n * base;
		n = n + is_base(str[i], base);
		i++;
	}
	fdf->color_exist = 1;
	if (ng)
		return (-n);
	return (n);
}
