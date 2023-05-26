/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <<mryoo@student.42.fr>>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:48:37 by mryoo             #+#    #+#             */
/*   Updated: 2023/05/17 20:05:28 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_free(char **p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

unsigned int	word_count(char const *s, char c)
{
	unsigned int	cnt;
	unsigned int	i;

	i = 0;
	cnt = 0;
	while (s[i])
	{
		if (s[i++] == c)
			continue ;
		cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

char	*ft_make_word(char const *s, char c)
{
	int		i;
	int		len;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**p;

	i = 0;
	j = 0;
	p = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!p)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			p[j] = ft_make_word(s + i, c);
			if (!p[j])
				return (ft_free(p));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	p[j] = 0;
	return (p);
}
