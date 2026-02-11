/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 16:33:57 by ssucha            #+#    #+#             */
/*   Updated: 2026/02/04 16:34:10 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Takes an integer as an argument and returns its absolute value.
 */
int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}
