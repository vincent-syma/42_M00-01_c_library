/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 16:02:42 by ssucha            #+#    #+#             */
/*   Updated: 2025/12/03 16:29:17 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a character on the standard output.
 * @return Number of successfully writen characters (1/-1)
 */
int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}
