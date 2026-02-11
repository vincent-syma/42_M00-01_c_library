/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:54:17 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 18:30:31 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks whether c is a 7-bit unsigned char value
 * that fits into the ASCII character set.
 * @return Nonzero if the character c falls into the tested class
 * and zero if not.
 */
int	ft_isascii(int c)
{
	unsigned char	ch;

	if (c == EOF)
		return (0);
	ch = (unsigned char)c;
	return (ch <= 127);
}
