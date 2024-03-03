/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:16:26 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		size;

	size = ft_strlen(s);
	dup = (char *)malloc(sizeof(char) * size + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*int main()
{
	char *s = "oi sou a ana!";

	printf("%s", ft_strdup(s));
}*/