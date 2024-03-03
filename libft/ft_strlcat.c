/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:16:42 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] && (i < n))
		i++;
	while (src[j] && (i + j + 1 < n))
	{
		dest[i + j] = src[j];
		j++;
	}
	if (i + j < n)
		dest[i + j] = '\0';
	while (src[j])
		j++;
	return (i + j);
}

/*int main()
{
	char src[] = "deus";
	char dest[] = "ola, bom dia";
	size_t n = 11;

	printf("%lu", ft_strlcat(dest, src, n));
}*/