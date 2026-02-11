/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 05:02:30 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 15:47:29 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief External functs: free
 * 
 * Takes as a parameter a node and frees the memory of the node’s content
 * using the function ’del’ given as a parameter and free the node.
 * Free the node itself but does NOT free the next node.
 * @param lst The node to free.
 * @param del The address of the function used to delete the content.
 * @return None.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
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
// 	tmp = test;
// 	while (test)
// 	{
// 		tmp = test->next;
// 		ft_lstdelone(test, free);
// 		test = tmp;
// 	}
// 	printf("Cleared\n");
// }
