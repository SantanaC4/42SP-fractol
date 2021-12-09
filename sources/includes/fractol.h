/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:32:15 by edrodrig          #+#    #+#             */
/*   Updated: 2021/12/08 20:45:46 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../../libraries/libft/libft.h"
# include "../../libraries/minilibx/mlx.h"
#include <math.h>
#include <stdio.h>

# define WIDTH		800
# define HEIGHT		600

typedef struct			s_env
{
	float				infinity;
	long double			min_x;
	long double			max_x;
	long double			min_y;
	long double			max_y;
	int							iteration;
}		t_env;
long double ft_map(long double x, long double in_min, long double in_max, long double out_min, long double out_max);

#endif
