/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:32:15 by edrodrig          #+#    #+#             */
/*   Updated: 2022/01/16 15:31:53 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"
# include <math.h>
# include <stdio.h>

# define WIDTH		600
# define HEIGHT		600
# define MWHEEL_UP 4
# define MWHEEL_DOWN 5
# define ESCAPE 0xff1b

typedef struct s_env
{
	double				zoom;
	float				infinity;
	double				min_x;
	double				max_x;
	double				min_y;
	double				max_y;
	int					iteration;
}		t_env;

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		mouse_hook_x;
	int		mouse_hook_y;
	t_env	e;
}				t_data;

/*Function to map one range to another */
double	ft_map(double x, double in_max, double out_min, double out_max);

/*Compute mandelbrot*/
int		mandelbrot_math(t_env *e, int x, int y);

/*Get mouse hooks to zooming the image*/
int		get_zoom(int key, int x, int y, t_data *img);

/*Check which key is pressed and make the respectively actions*/
int		select_key(int key, t_data *img);

/*Generate the image*/
void	fractol(t_data *img);

/*Compute the fractol color from iteration number*/
int		coloring(float iteration);

/*Store rgb numbers in four bytes*/
int		create_trgb(int t, int r, int g, int b);

/*Update image after hook call*/
int		expose_hook(t_data *img);

/*Initialize the mlx image*/
void	init_img(t_data *img);

/*Initialize the mlx*/
int		setup_env(t_data *img);

/*Run the window*/
void	run_window(t_data *img);
#endif
