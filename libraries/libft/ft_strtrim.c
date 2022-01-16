/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrodrig <edrodrig@student.42sp.org.b      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 21:05:52 by edrodrig          #+#    #+#             */
/*   Updated: 2021/09/16 23:26:43 by edrodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	trimmed_end = ft_strlen(s1);
	while (trimmed_end && ft_strchr(set, s1[trimmed_end]))
		trimmed_end--;
	return (ft_substr(s1, 0, trimmed_end + 1));
}
