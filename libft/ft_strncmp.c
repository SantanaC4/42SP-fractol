/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:46:12 by edrodrig          #+#    #+#             */
/*   Updated: 2021/09/19 21:09:31 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
