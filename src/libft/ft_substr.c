/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:25:53 by ssucha            #+#    #+#             */
/*   Updated: 2026/01/26 17:23:17 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: malloc >> FREE after use !!!
 * 
 * Allocates (with malloc(3)) and returns a substring from the string ’s’.
 * 
 * The substring begins at index ’start’ and is of maximum size ’len’.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	size_t	actual_len;
	char	*dst;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	actual_len = s_len - start;
	if (actual_len > len)
		actual_len = len;
	dst = malloc(actual_len +1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < actual_len)
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = 0;
	return (dst);
}

	// if (start >= s_len)
	// 	return (ft_calloc(1, 1));
