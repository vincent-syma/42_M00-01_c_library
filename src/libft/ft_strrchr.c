/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 00:21:50 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 17:47:26 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate character in string.
 * @return A pointer to the last occurrence of the character c
 * in the string s or NULL if the character is not found.
 * 
 * Here "character" means "byte";
 * these functions do not work with wide or multibyte characters.
 * 
 * The terminating null byte is considered part of the string,
 * so that if c is specified as '\0',
 * this function returns a pointer to the terminator.
 */
char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	ch = (unsigned char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}
