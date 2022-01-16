/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_math.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 21:27:18 by edrodrig          #+#    #+#             */
/*   Updated: 2022/01/16 15:26:16 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(void)
{
	t_data	img;

	img.e.zoom = 1;
	setup_env(&img);
	init_img(&img);
	fractol(&img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	run_window(&img);
	return (EXIT_SUCCESS);
}
