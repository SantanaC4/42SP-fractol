/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:27:18 by edrodrig          #+#    #+#             */
/*   Updated: 2021/12/09 16:50:09 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

typedef struct	s_data {
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

int		mandelbrot_math(t_env *e, int x, int y)
{
	long double mx;
	long double my;
	long double c_im;
	long double c_re;
	long double x_temp;

	e->iteration = 0;
	mx = 0.0;
	my = 0.0;
	c_re = ft_map(x, 0, WIDTH, e->min_x, e->max_x);
	c_im = ft_map(y, 0, HEIGHT, e->min_y, e->max_y);
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

//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dst;
//
//	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dst = color;
//}

int	main(void)
{
	int y;
	int x;
	t_env e;

	t_data	img;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	y = 0;
	e.min_x = -1.5f;
	e.max_x = 1.0f;
	e.min_y = -1.0f;
	e.max_y = 1.0f;
	e.infinity = 100;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (mandelbrot_math(&e, x, y) == 100)
			{
				img.addr[y * WIDTH + x] = 0x00000000;
			}
			else
			{
				img.addr[y * WIDTH + x] = 0xFFFFFFFF;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}

