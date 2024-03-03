/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:14:02 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 12:17:07 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;

	if (lst == NULL)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newnode = (t_list *)malloc(sizeof(t_list));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		newnode->next = NULL;
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
