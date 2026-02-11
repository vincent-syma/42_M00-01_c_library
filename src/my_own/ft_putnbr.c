/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 14:58:21 by ssucha            #+#    #+#             */
/*   Updated: 2025/12/08 18:52:37 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a number from integer argument on the standard output.
 * @return Number of successfully writen characters (/-1)
 */
int	ft_putnbr(int n)
{
	char	temp;
	int		len;

	temp = n;
	len = 0;
	if (n == -2147483648)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		n = -n;
		len += ft_putchar('-');
	}
	if (n > 9)
		len += ft_putnbr(n / 10);
	temp = (n % 10) + '0';
	len += ft_putchar(temp);
	return (len);
}
