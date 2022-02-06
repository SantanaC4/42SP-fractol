/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_math.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:07:03 by edrodrig          #+#    #+#             */
/*   Updated: 2022/02/04 23:11:43 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	mandelbrot_math(t_env *e, int x, int y)
{
	double	mx;
	double	my;
	double	c_im;
	double	c_re;
	double	x_temp;

	e->iteration = 0;
	mx = ft_map(x, WIDTH, e->min_max_x);
	my = ft_map(y, HEIGHT, e->min_max_y);
	c_re = ft_map(x, WIDTH, e->min_max_x);
	c_im = ft_map(y, HEIGHT, e->min_max_y);
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + c_re;
		my = 2.0f * mx * my + c_im;
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}

int	julia_math(t_env *e, int x, int y, double_t *complex_number)
{
	double_t	mx;
	double_t	my;
	double_t	x_temp;

	e->iteration = 0;
	mx = ft_map(x, WIDTH, e->min_max_x);
	my = ft_map(y, HEIGHT, e->min_max_y);
	while (e->iteration < e->infinity)
	{
		x_temp = (mx * mx - my * my) + complex_number[0];
		my = 2.0f * mx * my + complex_number[1];
		mx = x_temp;
		if ((mx * mx + my * my) > 4.0f)
			break ;
		e->iteration++;
	}
	return (e->iteration);
}
