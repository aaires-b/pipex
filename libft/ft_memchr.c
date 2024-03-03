/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:14:49 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*tmp;
	unsigned int	i;

	tmp = (unsigned char *) str;
	i = 0;
	while (i < n)
	{
		if (tmp[i] == (unsigned char)c)
			return ((unsigned char *)tmp + i);
		i++;
	}
	return (0);
}

/*int main()
{
	char str[] = "olabomdia";
	size_t n = 5;
	int c = 98;
	char *buf =  ft_memchr(str, c, n);
	
	printf("%s", buf);
	return (0);
}*/