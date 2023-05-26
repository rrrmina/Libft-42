/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <mryoo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:45:14 by mryoo             #+#    #+#             */
/*   Updated: 2023/05/08 20:45:15 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	if (dst == src || !len)
		return (dst);
	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (dst < src)
	{
		while (len--)
			*dst2++ = *src2++;
	}
	else if (dst > src)
	{
		while (len--)
			*(dst2 + len) = *(src2 + len);
	}
	return (dst);
}
