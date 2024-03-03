/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:16:22 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	d;

	d = (char) c;
	i = 0;
	while (str[i] && str[i] != d)
		i++;
	if (str[i] == d)
		return ((char *)str + i);
	return (0);
}
/*int main()
{
	char str[] = "anabel";
	int c = 97;

	printf("%s", ft_strchr(str, c));
	
}*/