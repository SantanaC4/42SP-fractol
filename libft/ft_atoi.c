/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:13:37 by edrodrig          #+#    #+#             */
/*   Updated: 2021/09/19 21:10:43 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if ((*str == '-' || *str == '+') && ft_isdigit(*(str + 1)))
		if (*str++ == '-')
			sign = -1;
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0');
	return (sign * num);
}
