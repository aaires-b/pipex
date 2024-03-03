/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/14 18:37:44 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	d;
	int		i;
	int		max;

	d = (char)c;
	i = 0;
	max = -1;
	while (str[i])
	{
		if (str[i] == d)
		{
			max = i;
		}
		i++;
	}
	if (str[i] == '\0' && d == '\0')
	{
		max = i;
		return ((char *) str + max);
	}
	else if (str[i] == '\0' && max == -1)
		return (NULL);
	else
		return ((char *) str + max);
}

/*int main()
{
	char str[] = "anabel";
	int c = 97;

	printf("%s", ft_strrchr(str, c));
	
}*/