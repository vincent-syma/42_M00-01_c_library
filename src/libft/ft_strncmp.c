/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/19 16:00:49 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 18:01:12 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief String compare - compares the first (at most) n bytes of s1 and s2.
 * @return An integer less than, equal to, or greater than zero if s1
 * (or the first n bytes thereof) is found, respectively, to be less than,
 * to match, or be greater than s2.
 * 
 * (Ascii difference between the first different pair of characters)
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	int			res;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i < (n -1) && (s1[i] == s2[i]))
		i++;
	res = (unsigned char)s1[i] - (unsigned char)s2[i];
	return (res);
}
