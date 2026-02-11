/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:03:34 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 17:01:58 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: free
 * 
 * Deletes and frees the given node and every successor of that node,
 * using the function ’del’ and free(3).
 * Finally, the pointer to the list must be set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the node.
 * @return None.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

// int	main(void)
// {
// 	int		*i = malloc(sizeof(int));
// 	char	*c = malloc(sizeof(char));
// 	char	*s;
// 	t_list	*test;
// 	t_list	*tmp;

// 	*i = 42;
// 	*c = 'A';
// 	s = ft_strdup("fortytwo");
//  	test = ft_lstnew(c);
// 	printf("t_list first = c: %c\n", *(char *)test->content);
// 	tmp = ft_lstnew(i);
// 	printf("t_list tmp = i: %d\n", *(int *)tmp->content);
// 	ft_lstadd_back(&test, tmp);
// 	tmp = ft_lstnew(s);
// 	printf("t_list tmp = s: %s\n", (char *)tmp->content);
// 	ft_lstadd_back(&test, tmp);
// 	ft_lstclear(&test, free);
// 	printf("Cleared\n");
// }
