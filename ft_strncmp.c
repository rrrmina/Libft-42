/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:45:39 by mryoo             #+#    #+#             */
/*   Updated: 2023/05/08 20:45:40 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	if (n <= 0)
		return (0);
	i = 0;
	while (i < n - 1 && p1[i] && p2[i])
	{
		if (p1[i] != p2[i])
			break ;
		i++;
	}
	return (p1[i] - p2[i]);
}
