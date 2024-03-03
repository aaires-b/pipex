/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:12:48 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_negative(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

static int	ft_getsize(int n)
{
	int				count;
	unsigned int	tmp;

	tmp = n;
	count = 1;
	if (n != 0)
	{
		count = 0;
		if (ft_negative(n) == 1)
		{
			tmp = -n;
			count++;
		}
		while (tmp > 0)
		{
			tmp /= 10;
			count++;
		}
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*intstr;
	int				i;
	int				digits;
	unsigned int	tmp;

	tmp = n;
	intstr = (char *)malloc(sizeof(char) * (ft_getsize(n) + 1));
	if (intstr == NULL)
		return (NULL);
	i = ft_getsize(n);
	if (ft_negative(n) == 1)
	{
		intstr[0] = '-';
		tmp = -n;
	}
	if (tmp == 0)
		intstr[0] = 48;
	while (tmp > 0)
	{
		digits = tmp % 10;
		intstr[--i] = digits + 48;
		tmp /= 10;
	}
	intstr[ft_getsize(n)] = '\0';
	return (intstr);
}

/*int main()
{
	int n = 1234;

	printf("%s", ft_itoa(n));
	return (0);
}*/