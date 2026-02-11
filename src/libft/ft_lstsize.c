/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssucha <ssucha@student.42prague.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 04:58:54 by ssucha            #+#    #+#             */
/*   Updated: 2025/11/24 13:47:47 by ssucha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Counts the number of nodes in a list.
 * @param lst The beginning of the list.
 * @return The length of the list.
 */
int	ft_lstsize(t_list *lst)
{
	int		count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

// int	main(void)
// {
// 	int		i;
// 	char	c;
// 	char	*s;
// 	t_list	*first;
// 	t_list	*tmp;

// 	i = 42;
// 	c = 'A';
// 	s = "fortytwo";
//  	first = ft_lstnew(&c);
// 	printf("t_list first = c: %c\n", *(char *)first->content);
// 	tmp = ft_lstnew(&i);
// 	printf("t_list tmp = i: %d\n", *(int *)tmp->content);
// 	ft_lstadd_front(&first, tmp);
// 	tmp = ft_lstnew(s);
// 	printf("t_list tmp = s: %s\n", (char *)tmp->content);
// 	ft_lstadd_front(&first, tmp);
// 	printf("List size: %d\n", ft_lstsize(first));
// 	while (first)
// 	{
// 		tmp = first->next;
// 		free(first);
// 		first = tmp;
// 	}
// }
