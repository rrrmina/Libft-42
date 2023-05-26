/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mryoo <<mryoo@student.42.fr>>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:22:51 by mryoo             #+#    #+#             */
/*   Updated: 2023/05/17 22:02:04 by mryoo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*res;
	void	*temp;

	if (!f || !del)
		return (NULL);
	newlst = 0;
	while (lst)
	{
		temp = (*f)(lst->content);
		res = ft_lstnew(temp);
		if (!res)
		{
			ft_lstclear(&newlst, del);
			free(temp);
			return (NULL);
		}
		ft_lstadd_back(&newlst, res);
		lst = lst->next;
	}
	return (newlst);
}
