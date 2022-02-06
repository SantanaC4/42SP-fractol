/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:35:43 by edrodrig          #+#    #+#             */
/*   Updated: 2022/02/05 17:59:21 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	fractol(t_data *img, int iteration)
{
	int	y;
	int	x;

	y = 0;
	img->e.min_x = -2.f * img->e.zoom;
	img->e.max_x = 2.0f * img->e.zoom;
	img->e.min_y = -2.0f * img->e.zoom;
	img->e.max_y = 2.0f * img->e.zoom;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (img->type == 'j')
				iteration = julia_math(&img->e, x, y, img->complex_number);
			else
				iteration = mandelbrot_math(&img->e, x, y);
			if (iteration == 100)
				img->addr[y * WIDTH + x] = 0x00000000;
			else
				img->addr[y * WIDTH + x] = coloring(((float)iteration) / 100.0);
			x++;
		}
		y++;
	}
}
