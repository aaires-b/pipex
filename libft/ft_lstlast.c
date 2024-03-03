/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:34:21 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
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
	new->next = new2;
	lst = ft_lstlast(lst);
	printf("%s", (char *)lst->content);

}*/
