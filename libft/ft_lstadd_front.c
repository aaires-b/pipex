/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:46:58 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
		new->next = *lst;
		*lst = new;
	}
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
	ft_lstadd_front(&lst, new2);
	while(lst)
	{
		printf("%s", (char *)lst->content);
		lst = lst->next;
	}
}*/