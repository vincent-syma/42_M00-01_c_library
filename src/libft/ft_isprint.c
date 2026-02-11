/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 22:54:17 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 18:30:38 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Checks for any printable character including space.
 * @return Nonzero if the character c falls into the tested class
 * and zero if not.
 */
int	ft_isprint(int c)
{
	unsigned char	ch;

	if (c == EOF)
		return (0);
	ch = (unsigned char)c;
	return (ch >= ' ' && ch <= '~');
}
