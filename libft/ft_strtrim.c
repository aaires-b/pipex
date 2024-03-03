/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:17:48 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 10:17:48 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	char			*trstr;
	unsigned int	j;
	unsigned int	a;

	i = 0;
	j = ft_strlen(s1);
	while (i < ft_strlen(s1) && ft_strchr(set, s1[i]) != 0)
		i++;
	while (j > i && ft_strchr(set, s1[j - 1]) != NULL)
		j--;
	a = j - i;
	trstr = (char *)malloc(sizeof(char) * a + 1);
	if ((s1 == 0 && set == 0) || trstr == NULL)
		return (NULL);
	j = 0;
	while (j < a)
	{
		trstr[j] = s1[i + j];
		j++;
	}
	trstr[j] = '\0';
	return (trstr);
}

/*int main() 
{
	char s1[] = "bodiabo";
	char set[] = "bo";
  
	printf("%s", ft_strtrim(s1, set));
	return 0;
}*/