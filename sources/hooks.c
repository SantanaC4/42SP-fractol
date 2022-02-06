/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:25:39 by edrodrig          #+#    #+#             */
/*   Updated: 2022/01/16 16:25:44 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	select_key(int key, t_data *img)
{
	if (key == ESCAPE)
	{
		mlx_destroy_image(img->mlx, img->img);
		mlx_destroy_window(img->mlx, img->mlx_win);
		mlx_destroy_display(img->mlx);
		free(img->mlx);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	get_zoom(int key, int x, int y, t_data *img)
{
	if (key == MWHEEL_UP)
		img->e.zoom *= 0.94;
	else if (key == MWHEEL_DOWN)
		img->e.zoom *= 1.1;
	img->mouse_hook_x = x;
	img->mouse_hook_y = y;
	fractol(img, 0);
	expose_hook(img);
	return (0);
}
