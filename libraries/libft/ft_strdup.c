/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 21:50:54 by edrodrig          #+#    #+#             */
/*   Updated: 2021/09/19 21:10:59 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*n;

	n = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (n == NULL)
		return (NULL);
	ft_memcpy(n, s, ft_strlen(s) + 1);
	return (n);
}
