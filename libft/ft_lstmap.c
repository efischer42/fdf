/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:29:51 by efischer          #+#    #+#             */
/*   Updated: 2018/11/13 14:20:47 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	if (!lst || !f)
		return (NULL);
	if (!(new = (t_list *)malloc(sizeof(lst))))
		return (NULL);
	new = f(lst);
	tmp = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new->next = (t_list *)malloc(sizeof(lst))))
			return (NULL);
		new->next = f(lst);
		new = new->next;
	}
	return (tmp);
}
