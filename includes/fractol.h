/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:32:15 by edrodrig          #+#    #+#             */
/*   Updated: 2022/02/11 18:40:12 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <math.h>
# include <stdio.h>
# include "../libraries/libft/libft.h"
# include "../libraries/minilibx/mlx.h"

# define WIDTH		600
# define HEIGHT		600
# define MWHEEL_UP 4
# define MWHEEL_DOWN 5
# define ESCAPE 0xff1b

typedef struct s_env
{
	int			iteration;
	float		infinity;
	double_t	zoom;
	double_t	min_max_y[2];
	double_t	min_max_x[2];
}		t_env;

typedef struct s_data
{
	char		**argv;
	char		type;
	int			*addr;
	int			bi;
	int			li;
	int			end;
	int			mouse_hook_x;
	int			mouse_hook_y;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	t_env		e;
	double_t	complex_number[2];
}	t_data;

/*Function to map one range to another */
double_t	ft_map(double_t x, double_t in_max, double_t out[2]);

/*Compute mandelbrot*/
int			mandelbrot_math(t_env *e, int x, int y);
int			julia_math(t_env *e, int x, int y, double_t complex_number[2]);

/*Get mouse hooks to zooming the image*/
int			get_zoom(int key, int x, int y, t_data *img);

/*Check which key is pressed and make the respectively actions*/
int			select_key(int key, t_data *img);

/*Generate the image*/
void		fractol(t_data *img, int interation);

/*Compute the fractol color from iteration number*/
int			coloring(float iteration);

/*Store rgb numbers in four bytes*/
int			create_trgb(int t, int r, int g, int b);

/*Update image after hook call*/
int			expose_hook(t_data *img);

/*Initialize the mlx image*/
void		init_img(t_data *img);

/*Initialize the mlx*/
int			setup_env(t_data *img);

/*Run the window*/
void		run_window(t_data *img);

/*Libft func*/
int			ft_strncmp(const char *str1, const char *str2, size_t num );
int			ft_isspace(int c);
int			ft_isdigit(int c);
float		ft_atof(const char *str);
#endif
