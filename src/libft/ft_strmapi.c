/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:57:52 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 18:00:56 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: malloc >> FREE after use !!!
 * 
 * Applies the function ’f’ to each character of the string ’s’,
 * and passing its index as first argument to create a new string
 * (with malloc(3)) resulting from successive applications of ’f’.
 * @return The string created from the successive applications of ’f’.
 * 
 * Returns NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (!s || !f)
		return (NULL);
	dest = malloc(ft_strlen(s) +1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = f(i, s[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}
