/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:00:01 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 17:01:41 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @param lst The beginning of the list.
 * @return Last node of the list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// int	main(void)
// {
// 	int		i;
// 	char	c;
// 	char	*s;
// 	t_list	*test;
// 	t_list	*tmp;

// 	i = 42;
// 	c = 'A';
// 	s = "fortytwo";
//  	test = ft_lstnew(&c);
// 	printf("t_list first = c: %c\n", *(char *)test->content);
// 	tmp = ft_lstnew(&i);
// 	printf("t_list tmp = i: %d\n", *(int *)tmp->content);
// 	ft_lstadd_front(&test, tmp);
// 	tmp = ft_lstnew(s);
// 	printf("t_list tmp = s: %s\n", (char *)tmp->content);
// 	ft_lstadd_front(&test, tmp);
// 	tmp = ft_lstlast(test);
// 	printf("Last of lists: %c\n", *(char *)tmp->content);
// 	while (test)
// 	{
// 		tmp = test->next;
// 		free(test);
// 		test = tmp;
// 	}
// }
