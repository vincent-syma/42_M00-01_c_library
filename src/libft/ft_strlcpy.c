/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 18:19:22 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/20 19:25:35 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy/catenate a string with truncation.
 * 
 * Copy  and  catenate  the input string into a destination string.
 * 
 * If the destination buffer, limited by its size, isn't large enough
 * to hold the copy, the resulting string is truncated
 * (but it is guaranteed to be null-terminated).
 * 
 * @param *dst destination string (source copied to this one)
 * @param *src source string
 * @param *dsize size of destination string buffer
 * 
 * @return The length of the total string that they tried to create
 * (as if truncation didn't occur).
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	i;

	i = 0;
	if (dsize > 0)
	{
		while (src[i] && (i < (dsize - 1)))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	return (ft_strlen(src));
}
