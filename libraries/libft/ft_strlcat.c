/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 02:40:02 by edrodrig          #+#    #+#             */
/*   Updated: 2021/08/31 21:29:54 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(dst);
	if (dstsize <= len)
		return (dstsize + ft_strlen(src));
	while (*src && len - (dstsize - 1))
		dst[len++] = *src++;
	dst[len] = '\0';
	return (len + ft_strlen(src));
}
