/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 21:10:52 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buffer, size_t n);

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*calloc;

	calloc = (void *)malloc(size * nmemb);
	if (!calloc)
		return (NULL);
	ft_bzero(calloc, nmemb * size);
	return (calloc);
}

/*int main()
{
	size_t nmemb = 5;
	size_t size = 4;
	void *tmp = ft_calloc(nmemb, size);
	unsigned int i;
	char *tmpdois = (char *)tmp;
	
	//if(tmp != NULL)
		//printf("correct");
	//else
		//printf("not good");
		i = 0;
	while(i < nmemb)
	{
		printf("%d", tmpdois[i]);
		i++;
	}
	
}*/