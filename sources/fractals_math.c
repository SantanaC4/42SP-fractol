/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:27:18 by edrodrig          #+#    #+#             */
/*   Updated: 2022/01/09 12:54:36 by edrodrig         ###   ########.fr       */
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

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int coloring(float iteration)
{
	float r;
	float g;
	float b;
	int ir;
	int ig;
	int ib;

	r = 9*(1 - iteration)*pow(iteration, 3)*255;
	g = 15*pow((1 - iteration), 2)*pow(iteration, 2)*255;
	b = 8.5*pow((1 - iteration), 3)*iteration*255;

	ir = 255.999 * r;
	ig = 255.999 * g;
	ib = 255.999 * b;
	return (create_trgb(0, ir, ig, ib));
}

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

int	main(void)
{
	int y;
	int x;
	int iteration;
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
			iteration = mandelbrot_math(&e, x, y);
			if (iteration == 100)
				img.addr[y * WIDTH + x] =  0x00000000;
			else
				img.addr[y * WIDTH + x] = coloring(((float)iteration)/100.0);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
