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

static void	error_handler(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("\nTHE AVAILABLE SETS ARE:\n mandelbrot;\n julia;\n");
		exit (EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1], "mandelbrot", 11) != 0
		&& (!(ft_strncmp(argv[1], "julia", 6) == 0 && argc > 3)))
	{
		if (ft_strncmp(argv[1], "julia", 6) == 0)
		{
			printf("\nTHE COMPLEX NUMBER MUST BE GIVEN IN TWO\
					SEPARATE ARGUMENTS.\n");
			printf("                (ex: julia -0.73 0.14).\n");
			printf("THE FIRST NUMBER -0.73 IS THE REAL PART (+0.0 OR -0.0)\n");
			printf("AND THE SECOND NUMBER 0.14 IS THE IMAGINARY\
					 PART(+0.0 OR -0.0).\n");
			exit (EXIT_FAILURE);
		}
		else
		{
			printf("#####INVALID OPTION######\n");
			printf("THE AVAILABLE SETS ARE:\n mandelbrot;\n julia;\n");
			exit (EXIT_FAILURE);
		}
	}
}

int	main(int argc, char *argv[])
{
	t_data	img;

	error_handler(argc, argv);
	img.e.zoom = 1;
	img.argv = argv;
	setup_env(&img);
	init_img(&img);
	fractol(&img, 0);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	run_window(&img);
	return (EXIT_SUCCESS);
}
