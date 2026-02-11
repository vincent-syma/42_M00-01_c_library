/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:14:47 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 17:56:55 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Erases the data in the n bytes of the memory
 * starting at the location pointed to by s,
 * by writing zeros (bytes containing '\0') to that area.
 * @return Void.
 */
void	ft_bzero(void *s, size_t n)
{
	s = ft_memset(s, 0, n);
}
