/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 15:26:42 by edrodrig          #+#    #+#             */
/*   Updated: 2021/09/19 19:46:10 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s_end;

	s_end = ft_strchr(str, '\0');
	while (*s_end != (char)c)
		if (s_end-- == str)
			return (NULL);
	return ((char *)s_end);
}
