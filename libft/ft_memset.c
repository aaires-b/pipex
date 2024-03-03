/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:15:26 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buffer, int c, size_t n)
{
	char			*new_buffer;
	unsigned int	i;

	new_buffer = (char *) buffer;
	i = 0;
	while (i < n)
	{
		new_buffer[i] = c;
		i++;
	}
	return (new_buffer);
}

/*int main()
{
	char buffer[7];
	int i;
	
	i = 0;
	ft_memset(buffer, 'b', sizeof(char) * 7);
	while(i < 7)
	{
		printf("%c", buffer[i]);
		i++;
	}
	return(0);
}*/
