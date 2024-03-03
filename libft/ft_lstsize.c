/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:46:45 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*int main()
{
	t_list *lst;
	t_list *new;
	t_list *new2;
	int d;

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
	d = ft_lstsize(lst);
	printf("%d", d);
}*/	