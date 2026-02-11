/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:54:24 by ssucha            #+#    #+#             */
/*   Updated: 2026/01/28 21:09:12 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: malloc >> FREE after use !!!
 * 
 * Allocates (with malloc(3)) and returns a string 
 * representing the integer n received as an argument.
 * 
 * Negative numbers must be handled.
 * @return The string representing the integer.
 * 
 * NULL if the allocation fails.
 */
char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	num;

	len = ft_count_digits(n);
	str = malloc(len +1);
	if (!str)
		return (NULL);
	num = n;
	str[len] = 0;
	if (num == 0)
		str[0] = '0';
	if (num < 0)
	{
		num = -num;
		str[0] = '-';
	}
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
