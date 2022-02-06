/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 17:59:06 by edrodrig          #+#    #+#             */
/*   Updated: 2022/02/05 18:04:38 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"
#include <math.h>

int	ft_strncmp(const char *str1, const char *str2, size_t num )
{
	while (num-- && (*str1 || *str2))
	{
		if (*str1 != *str2)
			return ((unsigned char)*(str1) - (unsigned char)*(str2));
		str1++;
		str2++;
	}
	return (0);
}

float	ft_atof(const char *str)
{
	float	ret;
	float	sign;
	float	dec;
	int		i;

	ret = 0.0;
	dec = 0.0;
	sign = 1.0;
	while (ft_isspace(*str) || *str == '-')
	{
		if (*str == '-')
			sign = -1.0;
		str++;
	}
	while (ft_isdigit(*str))
		ret = ret * 10 + (*str++ - '0');
	i = -1;
	if (*str == '.' && *str++)
	{
		while (ft_isdigit(*str))
			dec += (pow(10, i--) * (*str++ - '0'));
	}
	return (sign * (ret + dec));
}

int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || (c == 32))
		return (8192);
	else
		return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
