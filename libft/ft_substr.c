/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:17:58 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:17:58 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	i;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	while (s[i + start] && (i < len))
		i++;
	if (s == NULL)
		return (NULL);
	substr = (char *)malloc(sizeof(char) * i + 1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len && (start < ft_strlen(s)))
	{
		substr[i] = s[start];
		start++;
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*int main()
{
	char s[] = "bom dia";
	unsigned int start = 5;
	size_t len = 4;
	printf("%s", ft_substr(s, start, len));
	return(0);
}*/