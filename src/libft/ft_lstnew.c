/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 04:55:17 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 11:36:26 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: malloc >> FREE after use!
 * 
 * Allocates (with malloc(3)) and returns a new node.
 * The member variable ’content’ is initialized with
 * the value of the parameter ’content’.
 * The variable ’next’ is initialized to NULL.
 * @return The new node.
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// int	main(void)
// {
// 	int		i;
// 	char	c;
// 	char	*s;
// 	t_list	*test;

// 	i = 42;
// 	c = 'A';
// 	s = "fortytwo";
// 	test = ft_lstnew(&i);
// 	printf("i: %d\n", *(int *)test->content);
// 	free(test);
// 	test = ft_lstnew(&c);
// 	printf("c: %c\n", *(char *)test->content);
// 	free(test);
// 	test = ft_lstnew(s);
// 	printf("s: %s\n", (char *)test->content);
// 	free(test);
// }
