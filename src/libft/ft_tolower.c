/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 16:43:17 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/28 13:01:30 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Converts uppercase character (int) to lowercase.
 * @return Character in lowercase.
 */
int	ft_tolower(int c)
{
	if (c == EOF)
		return (EOF);
	if (ft_isupper(c))
		c += 32;
	return (c);
}
