/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:11:57 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		i;
	int		j;
	int		a;

	if (s1 == 0 && s2 == 0)
		return (NULL);
	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	i = -1;
	j = -1;
	a = 0;
	while (s1[++i])
	{
		newstr[a] = s1[i];
		a++;
	}
	while (s2[++j])
	{
		newstr[a] = s2[j];
		a++;
	}
	newstr[a] = '\0';
	return (newstr);
}

/*int main()
{
	char s1[] = "bom";
	char s2[] = "dia";
	printf("%s", ft_strjoin(s1, s2));
	return(0);
}*/