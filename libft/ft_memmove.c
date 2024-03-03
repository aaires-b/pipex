/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/09/14 19:57:39 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int						i;
	unsigned char			*new_dest;
	unsigned char			*new_src;

	new_dest = (unsigned char *) dest;
	new_src = (unsigned char *) src;
	i = n - 1;
	if (src < dest)
	{
		while (i >= 0)
		{
			new_dest[i] = new_src[i];
			i--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*int main()
{
	char src[] = "1234567890";
	char *dest;
	
	dest = ft_memmove(src + 2, src, strlen(src) + 1);
	printf("%s", src);
}*/
