/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 21:12:45 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buffer, size_t n)
{
	char			*new_buffer;
	unsigned int	i;

	new_buffer = (char *) buffer;
	i = 0;
	while (i < n)
	{
		new_buffer[i] = 0;
		i++;
	}
}

/*int main()
{
	char buffer[10];
	int i;

	i = 0;
	ft_bzero(buffer, sizeof(char) * 10);
	while(i < 10)
	{
		printf("%d", buffer[i]);
		i++;
	}
	return(0);
}*/