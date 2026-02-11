/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 04:57:37 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 12:53:58 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Adds the node ’new’ at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the node to be added to the list.
 * @return None.
 */
void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	int		i;
// 	char	c;
// 	t_list	*first;
// 	t_list	*test;
// 	t_list	*tmp;

// 	i = 42;
// 	c = 'A';
// 	first = ft_lstnew(&c);
// 	printf("t_list first = c: %c\n", *(char *)first->content);
// 	test = ft_lstnew(&i);
// 	printf("t_list test = i: %d\n", *(int *)test->content);
// 	ft_lstadd_front(&first, test);
// 	printf("AFTER:\nt_list first = i: %d\n", *(int *)first->content);
// 	tmp = first->next;
// 	printf("t_list first->next = c: %c\n", *(char *)tmp->content);
// 	while (first)
// 	{
// 		tmp = first->next;
// 		free(first);
// 		first = tmp;
// 	}
// }
