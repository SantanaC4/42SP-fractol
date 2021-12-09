/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 09:13:14 by edrodrig          #+#    #+#             */
/*   Updated: 2021/12/08 09:13:38 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


long double ft_map(long double x, long double in_min, long double in_max, long double out_min, long double out_max)
{
	long double ret;
	long double a;
	long double b;

	a = (out_min - out_max) / (in_min - in_max);
	b = ((out_max * in_min) - in_max * out_min) / (in_min - in_max);

	ret = a*x + b;

	return ret;
}
