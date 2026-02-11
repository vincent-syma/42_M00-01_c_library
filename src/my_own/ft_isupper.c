/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 20:04:10 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/20 15:15:10 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks for an alphabetic character (int) in uppercase.
 * @return Nonzero if the character c falls into the tested class,
 * and zero if not.
 */
int	ft_isupper(int c)
{
	unsigned char	ch;

	if (c == EOF)
		return (0);
	ch = (unsigned char)c;
	return (ch >= 'A' && ch <= 'Z');
}
