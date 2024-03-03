/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaires-b <aaires-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:11:53 by aaires-b          #+#    #+#             */
/*   Updated: 2023/10/02 13:43:00 by aaires-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	wordlength(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static	int	word_count(const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		if (s[i])
			i++;
	}
	return (count);
}

static	void	ft_freeloop(char **finalstr, int total_len)
{
	int	i;

	i = 0;
	while (i < total_len)
	{
		free(finalstr[i]);
		i++;
	}
	free(finalstr);
}

char	*wordsmalloc(char const **s, char c)
{
	int		word_len;
	char	*word;
	int		j;

	word_len = wordlength(*s, c);
	word = (char *)malloc(sizeof(char) * (word_len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < word_len)
	{
		word[j] = (*s)[j];
		j++;
	}
	word[word_len] = '\0';
	*s += word_len;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**finalstr;
	int		i;

	if (!s)
		return (NULL);
	finalstr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!finalstr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		finalstr[i] = wordsmalloc(&s, c);
		if (!finalstr[i])
		{
			ft_freeloop(finalstr, i);
			return (NULL);
		}
		i++;
	}
	finalstr[i] = NULL;
	return (finalstr);
}

/*int main()
{
	char s[] = "ana bel monte";
	char c = ' ';
	char **finalstr;
	int i;

	i = 0;
	finalstr = ft_split(s, c);
	while(finalstr[i])
	{
		printf("%s\n", finalstr[i]);
		i++;
	}
	return (0);
}*/