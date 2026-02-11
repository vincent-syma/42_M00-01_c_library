/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:01:14 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/20 20:49:27 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Compare memory areas.
 * 
 * Compares the first n bytes (each interpreted as unsigned char)
 * of the memory areas s1 and s2.
 * @return An integer less than, equal to, or greater than zero
 * if the first n bytes of s1 is found, respectively, to be less than,
 * to match, or be greater than the first n bytes of s2.
 * 
 * For a nonzero return value, the sign is determined by the sign
 * of the difference between the first pair of bytes
 * (interpreted as unsigned char) that differ in s1 and s2.
 * 
 * If n is zero, the return value is zero.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
