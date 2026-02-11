/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 11:35:18 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/27 17:35:43 by ssucha           ###   ########.fr       */
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
 * @param *dst destination string (source added to the end of this one)
 * @param *src source string
 * @param *dsize size of destination string buffer
 * 
 * @return The length of the total string that they tried to create
 * (as if truncation didn't occur).
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t	d;
	size_t	s;
	size_t	i;

	s = ft_strlen(src);
	d = 0;
	while (d < dsize && dst[d])
		d++;
	if (d >= dsize)
		return (dsize + s);
	i = 0;
	while (src[i] && ((d + i) < (dsize - 1)))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = 0;
	return (d + s);
}
