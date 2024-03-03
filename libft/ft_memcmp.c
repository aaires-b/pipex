/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 21:13:20 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	buf1 = (unsigned char *) str1;
	buf2 = (unsigned char *) str2;
	i = 0;
	while (i < n)
	{
		if (buf1[i] != buf2[i])
			return (buf1[i] - buf2[i]);
		i++;
	}
	return (0);
}

/*int main()
{
	char str1[] = "ola";
	char str2[] = "olc";
	int ary1[] = {1, 2, 3, 4 };
	int ary2[] = {1, 2, 4, 6 };

	printf("%d", ft_memcmp(str1, str2, 3));
	printf("%d", ft_memcmp(ary1, ary2, sizeof(int) * 4));
	return(0);
}*/