/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:43:17 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/28 13:01:50 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts lowercase character (int) to uppercase.
 * @return Character in uppercase.
 */
int	ft_toupper(int c)
{
	if (c == EOF)
		return (EOF);
	if (ft_islower(c))
		c -= 32;
	return (c);
}
