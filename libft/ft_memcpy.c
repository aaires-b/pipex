/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/06 21:13:26 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char			*wannabe_dest;
	char			*wannabe_src;
	unsigned int	i;

	wannabe_dest = (char *) dest;
	wannabe_src = (char *) src;
	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		wannabe_dest[i] = wannabe_src[i];
		i++;
	}
	return (wannabe_dest);
}

/*int main()
{
	char src[] = "ola";
	char dest[100];

	ft_memcpy(dest, src, strlen(src) + 1);
	printf("%s", dest);
}*/