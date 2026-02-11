/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 22:39:24 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/19 17:59:31 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Locate character in string.
 * @return A pointer to the first occurence of matched character
 * in the string s or NULL if the character is not found.
 * 
 * Here "character" means "byte";
 * this function do not work with wide or multibyte characters.
 * 
 * The terminating null byte is considered part of the string,
 * so that if c is specified as '\0', these functions return
 * a pointer to the terminator.
 */
char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	unsigned char	ch;

	i = 0;
	ch = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == ch)
		return ((char *) s + i);
	return (NULL);
}
