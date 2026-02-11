/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 02:50:11 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 18:01:54 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Tells if character is part of defined charset.
 * @return 1 if charset, 0 if not.
 */
static int	ft_is_charset(char s, const char *c)
{
	int	i;

	i = 0;
	while (c[i])
	{
		if (s == c[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief External functs: malloc >> FREE after use !!!
 * 
 * Allocates (with malloc(3)) and returns a copy of ’s1’
 * with the characters specified in ’set’ removed
 * from the beginning and the end of the string.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	j;
	size_t	end;
	char	*dest;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (start < end && ft_is_charset(s1[start], set))
		start++;
	while (end > start && ft_is_charset(s1[end -1], set))
		end--;
	dest = malloc(end - start +1);
	if (!dest)
		return (NULL);
	j = 0;
	while (start < end)
		dest[j++] = s1[start++];
	dest[j] = 0;
	return (dest);
}
