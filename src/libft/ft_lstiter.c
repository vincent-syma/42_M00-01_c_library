/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:04:37 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 16:11:43 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’
 * on the content of each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @return None.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// void	ft_strtolower(void *s)
// {
// 	size_t	i;
// 	size_t	len;
// 	char	*str;

// 	str = (char *)s;
// 	i = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		str[i] = ft_tolower(str[i]);
// 		i++;
// 	}
// }

// void	ft_strtoupper(void *s)
// {
// 	size_t	i;
// 	size_t	len;
// 	char	*str;

// 	str = (char *)s;
// 	i = 0;
// 	len = ft_strlen(str);
// 	while (i < len)
// 	{
// 		str[i] = ft_toupper(str[i]);
// 		i++;
// 	}
// }
// int	main(void)
// {
// 	char	*i1 = ft_strdup("");
// 	char	*i2 = ft_strdup("42");
// 	char	*i3 = ft_strdup("Hello, World!");
// 	t_list	*test;
// 	t_list	*tmp;

//  	test = ft_lstnew(i1);
// 	printf("t_list first = i1: %s\n", (char *)test->content);
// 	tmp = ft_lstnew(i2);
// 	printf("t_list tmp = i2: %s\n", (char *)tmp->content);
// 	ft_lstadd_back(&test, tmp);
// 	tmp = ft_lstnew(i3);
// 	printf("t_list tmp = i3: %s\n", (char *)tmp->content);
// 	ft_lstadd_back(&test, tmp);
// 	tmp = test;
// 	printf("\nBefore:\n");
// 	while (tmp)
// 	{
// 		printf("test content = %s;\t", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstiter(test, ft_strtolower);
// 	tmp = test;
// 	printf("\n\nAfter ft_tolower:\n");
// 	while (tmp)
// 	{
// 		printf("test content = %s;\t", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstiter(test, ft_strtoupper);
// 	tmp = test;
// 	printf("\n\nAfter ft_toupper:\n");
// 	while (tmp)
// 	{
// 		printf("test content = %s;\t", (char *)tmp->content);
// 		tmp = tmp->next;
// 	}
// 	ft_lstclear(&test, free);
// 	printf("\n\nCleared\n");
// }
