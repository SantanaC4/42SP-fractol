/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:35:43 by edrodrig          #+#    #+#             */
/*   Updated: 2022/01/16 16:35:45 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void fractol(t_data *img)
{
	int y;
	int x;
	int iteration;
	y = 0;
	img->e.min_x = -2.f * img->e.zoom;
	img->e.max_x = 2.0f * img->e.zoom;
	img->e.min_y = -2.0f * img->e.zoom;
	img->e.max_y = 2.0f * img->e.zoom;
	img->e.infinity = 100;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			//iteration = mandelbrot_math(&e, -2 + ((double)x / WIDTH) * 4, -2 + ((double)y / HEIGHT) * 4);
			iteration = mandelbrot_math(&img->e, x, y);
			if (iteration == 100)
				img->addr[y * WIDTH + x] =  0x00000000;
			else
				img->addr[y * WIDTH + x] = coloring(((float)iteration)/100.0);

			x++;
		}
		y++;
	}
}
