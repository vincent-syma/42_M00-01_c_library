/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:44:24 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/21 19:19:18 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Malloc >> FREE after use !!!
 *
 * Duplicate a string.
 *
 * Memory for the new string is obtained  with  malloc(3),
 * and can be freed with free(3).
 *
 * ERRORS: ENOMEM Insufficient memory available to allocate duplicate string.
 *
 * @return On success, returns a pointer to a new string
 which is a duplicate of the string s.
 *
 * It  returns NULL if insufficient memory was available,
 * with errno set to indicate the cause of the error.
 */
char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	dest = malloc(ft_strlen(src) + 1);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
