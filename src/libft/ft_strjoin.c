/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 13:17:57 by ssucha            #+#    #+#             */
/*   Updated: 2026/01/26 17:18:32 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: malloc >> FREE after use !!!
 * 
 * Allocates (with malloc(3)) and returns a new string,
 * which is the result of the concatenation of ’s1’ and ’s2’.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new = malloc(len_s1 + len_s2 + 1);
	if (!new)
		return (NULL);
	ft_memcpy(new, s1, len_s1);
	ft_memcpy(new + len_s1, s2, len_s2);
	new[len_s1 + len_s2] = 0;
	return (new);
}

// /**
//  * @brief External functs: malloc >> FREE after use !!!
//  * 
//  * Allocates (with malloc(3)) and returns a new string,
//  * which is the result of the concatenation of ’s1’ and ’s2’.
//  * @return The new string. NULL if the allocation fails.
//  */
// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*str;
// 	size_t	len_s1;
// 	size_t	len_s2;
// 	size_t	len;

// 	len_s1 = ft_strlen(s1);
// 	len_s2 = ft_strlen(s2);
// 	len = len_s1 + len_s2;
// 	str = malloc(len +1);
// 	if (!str)
// 		return (NULL);
// 	ft_strlcpy(str, s1, len_s1 +1);
// 	ft_strlcat(str, s2, len +1);
// 	return (str);
// }
