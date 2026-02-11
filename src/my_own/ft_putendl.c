/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 11:33:36 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/20 15:11:52 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Writes a string and a newline on the standard output.
 * @return Void.
 */
void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
