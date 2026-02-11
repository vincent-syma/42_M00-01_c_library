/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:01:13 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 14:03:32 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None.
 */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = new;
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
// 	ft_lstadd_back(&test, tmp);
// 	tmp = ft_lstnew(s);
// 	printf("t_list tmp = s: %s\n", (char *)tmp->content);
// 	ft_lstadd_back(&test, tmp);
// 	tmp = ft_lstlast(test);
// 	printf("Last of lists: %s\n", (char *)tmp->content);
// 	while (test)
// 	{
// 		tmp = test->next;
// 		free(test);
// 		test = tmp;
// 	}
// }
