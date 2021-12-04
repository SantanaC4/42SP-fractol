/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 20:46:18 by edrodrig          #+#    #+#             */
/*   Updated: 2021/10/15 23:20:08 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*n;

	if (!s1 || !s2)
		return (NULL);
	n = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s1, ft_strlen(s1));
	ft_memcpy(n + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	return (n);
}
