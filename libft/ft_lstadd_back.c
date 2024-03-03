/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 16:54:28 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:28:50 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

/*int main()
{
	t_list *lst;
	t_list *new;
	t_list *new2;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (1);
	new->content = (char *) "bel";
	new->next = NULL;
	
	lst = new;
	new2 = (t_list *)malloc(sizeof(t_list));
	if (!new2)
		return (1);
	new2->content =(char *)"ana";
	new2->next = NULL;
	ft_lstadd_back(&lst, new2);
	while(lst)
	{
		printf("%s", (char *)lst->content);
		lst = lst->next;
	}
}*/