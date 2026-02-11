/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:05:53 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 16:55:01 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: malloc, free
 * 
 * Iterates the list ’lst’ and applies the function ’f’
 * on the content of each node.
 * Creates a new list resulting of the successive applications
 * of the function ’f’.
 * The ’del’ function is used to delete the content of a node if needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content
 * of a node if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*newlist;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		content = f(lst->content);
		if (!content)
			return (ft_lstclear(&newlist, del), NULL);
		new = ft_lstnew(content);
		if (!new)
		{
			del(content);
			return (ft_lstclear(&newlist, del), NULL);
		}
		ft_lstadd_back(&newlist, new);
		lst = lst->next;
	}
	return (newlist);
}

// void	*ft_strtolower(void *s)
// {
// 	size_t	i;
// 	size_t	len;
// 	char	*str;
// 	char	*res;

// 	str = (char *)s;
// 	res = ft_strdup(str);
// 	i = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		res[i] = ft_tolower(str[i]);
// 		i++;
// 	}
// 	return (res);
// }

// void	*ft_strtoupper(void *s)
// {
// 	size_t	i;
// 	size_t	len;
// 	char	*str;
// 	char	*res;

// 	str = (char *)s;
// 	res = ft_strdup(str);
// 	i = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		res[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// 	return (res);
// }
// int	main(void)
// {
// 	char	*i1 = ft_strdup("");
// 	char	*i2 = ft_strdup("42");
// 	char	*i3 = ft_strdup("Hello, World!");
// 	t_list	*test;
// 	t_list	*tmp;
// 	t_list	*lower;
// 	t_list	*upper;

//  	test = ft_lstnew(i1);
// 	ft_lstadd_back(&test, ft_lstnew(i2));
// 	ft_lstadd_back(&test, ft_lstnew(i3));
// 	tmp = test;
// 	printf("\nBefore:\n");
// 	while (tmp)
// 	{
// 		printf("test content = %s;\t", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	lower = ft_lstmap(test, ft_strtolower, free);
// 	tmp = lower;
// 	printf("\n\nAfter ft_tolower:\n");
// 	while (tmp)
// 	{
// 		printf("test content = %s;\t", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	upper = ft_lstmap(test, ft_strtoupper, free);
// 	tmp = upper;
// 	printf("\n\nAfter ft_toupper:\n");
// 	while (tmp)
// 	{
// 		printf("test content = %s;\t", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&test, free);
// 	ft_lstclear(&lower, free);
// 	ft_lstclear(&upper, free);
// 	printf("\n\nCleared\n");
// }
