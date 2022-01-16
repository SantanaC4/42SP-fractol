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
