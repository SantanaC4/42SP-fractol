/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:13:14 by edrodrig          #+#    #+#             */
/*   Updated: 2022/01/16 15:26:30 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_img(t_data *img)
{
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = (int *)mlx_get_data_addr(img->img, &img->bi, &img->li,
			&img->end);
}

int	setup_env(t_data *img)
{
	img->mlx = mlx_init();
	if (!(img->mlx))
	{
		perror("mlx_init error");
		exit(0);
	}
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Hello world!");
	img->type = img->argv[1][0];
	img->e.infinity = 100;
	if (img->type == 'j')
	{
		img->complex_number[0] = ft_atof(img->argv[2]);
		img->complex_number[1] = ft_atof(img->argv[3]);
	}
	return (0);
}

void	run_window(t_data *img)
{
	mlx_mouse_hook(img->mlx_win, get_zoom, img);
	mlx_key_hook(img->mlx_win, select_key, img);
	mlx_loop(img->mlx);
}

int	expose_hook(t_data *img)
{
	mlx_do_sync(img->mlx);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
	return (0);
}

double	ft_map(double x, double in_max, double out_min, double out_max)
{
	double	ret;
	double	a;
	double	b;
	double	in_min;

	in_min = 0;
	a = (out_min - out_max) / (in_min - in_max);
	b = ((out_max * in_min) - in_max * out_min) / (in_min - in_max);
	ret = a * x + b;
	return (ret);
}
