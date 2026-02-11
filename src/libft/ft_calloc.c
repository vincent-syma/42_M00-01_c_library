/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:12:10 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/25 15:25:54 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: malloc >> FREE after use !!!
 * 
 * The  calloc() function allocates memory for an array of nmemb elements
 * of size bytes each and returns a pointer to the allocated memory.
 * 
 * The memory is set to zero.
 * 
 * If nmemb or size is 0, then calloc() returns a unique pointer value
 * that can later be successfully passed to free().
 * 
 * If the multiplication of nmemb and size would result in integer overflow,
 * then calloc() returns an error.
 * 
 * ERRORS:
 * 
 * calloc() can fail with the following error:
 * ENOMEM Out of memory. Possibly, the application hit the RLIMIT_AS
 * or RLIMIT_DATA limit described in getrlimit(2).
 * 
 * Another reason could be that the number of mappings created
 * by the caller process exceeded the limit specified by
 * /proc/sys/vm/max_map_count.
 * 
 * @return A pointer to the allocated memory,
 * which is suitably aligned for any type that fits into the
 * requested size or less.
 * 
 * On error, this function returns NULL and set errno.
 * 
 * Attempting to allocate more than PTRDIFF_MAX bytes is considered an error,
 * as an object that large could cause later pointer subtraction to overflow.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	total_size;

	if (size != 0 && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	array = malloc(total_size);
	if (!array)
		return (NULL);
	ft_bzero(array, total_size);
	return (array);
}
