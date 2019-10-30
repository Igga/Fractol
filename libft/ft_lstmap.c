/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 14:18:16 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/16 20:29:36 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_list	*del(t_list *lst)
{
	t_list	*save;

	while (lst)
	{
		save = lst;
		lst = lst->next;
		if (save->content)
			free(save->content);
		free(save);
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*save;
	t_list	*ans;

	if (!lst || !f)
		return (NULL);
	ans = f(lst);
	if (!(save = ft_lstnew(ans->content, ans->content_size)))
		return (NULL);
	ret = save;
	lst = lst->next;
	while (lst)
	{
		ans = f(lst);
		if (!(ret->next = ft_lstnew(ans->content, ans->content_size)))
			return (del(save));
		ret = ret->next;
		lst = lst->next;
	}
	return (save);
}
