/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:17:08 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (needle[j] == '\0')
		return ((char *) haystack);
	while (haystack[i] && (i < n))
	{
		while (haystack[i + j] == needle[j] && haystack[i + j] && (i + j) < n)
			j++;
		if (needle[j] == '\0')
			return ((char *) haystack + i);
		i++;
		j = 0;
	}
	return (0);
}

/*int main()
{
	char hay[] = "olabomdia";
	char needle[] = "bom";
	size_t n = 5;

	printf("%s", ft_strnstr(hay, needle, n));
}*/
