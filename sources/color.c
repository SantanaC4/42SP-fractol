/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 16:45:11 by edrodrig          #+#    #+#             */
/*   Updated: 2022/01/16 16:45:12 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	coloring(float iteration)
{
	int			ir;
	int			ig;
	int			ib;
	float		rgb[3];

	rgb[0] = 9 * (1 - iteration) * pow(iteration, 3) * 255;
	rgb[1] = 15 * pow((1 - iteration), 2) * pow(iteration, 2) * 255;
	rgb[2] = 8.5 * pow((1 - iteration), 3) * iteration * 255;
	ir = 255.999 * rgb[0];
	ig = 255.999 * rgb[1];
	ib = 255.999 * rgb[2];
	return (create_trgb(0, ir, ig, ib));
}
