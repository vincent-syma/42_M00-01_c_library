/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:00:35 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/27 17:12:42 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Length of a substring - ends with char c or with end of the string.
 * @return Length of a substring (int).
 */
static int	ft_wlen(int i, const char *s, char c)
{
	int	len;

	len = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (len);
		i++;
		len++;
	}
	return (len);
}

/**
 * @brief word count, counts substrings divided by char c
 * @return number of substrings (size_t)
 */
static size_t	ft_wc(const char *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (count);
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

/**
 * @brief freeing the whole array of allocated subarrays (when malloc fails)
 * @return NULL - empty array
 */
static char	**ft_free_partial(char **array, size_t filled)
{
	while (filled > 0)
		free(array[--filled]);
	free(array);
	return (NULL);
}

/**
 * @brief External functs: malloc, free >> FREE after succesful use !!!

/Allocates (with malloc(3)) and returns an array of strings obtained
/by splitting ’s’ using the character ’c’ as a delimiter.

The array must end with a NULL pointer.
 * @return The array of new strings resulting from the split.

 NULL if the allocation fails.
 */
char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	j;
	size_t	len;

	array = malloc((ft_wc(s, c) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	j = 0;
	while (s && s[i])
	{
		while (s[i] && (s[i] == c))
			i++;
		if (!s[i])
			break ;
		len = ft_wlen(i, s, c);
		array[j] = ft_substr((char const *)(s + i), 0, len);
		if (!array[j])
			return (ft_free_partial(array, j));
		j++;
		i += len;
	}
	array[j] = NULL;
	return (array);
}
