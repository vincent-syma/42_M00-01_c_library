/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:28:29 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/25 15:32:08 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copy memory area.
 * Copies n bytes from memory area src to memory area dest.
 * The memory areas may overlap: copying takes place as though the bytes
 * in src are first copied into a temporary array that does not overlap
 * src or dest, and the bytes are then copied from the temporary array
 * to dest.
 * @return A pointer to dest.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (d < s)
	{
		i = 0;
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
		while (n-- > 0)
			d[n] = s[n];
	return (dest);
}
