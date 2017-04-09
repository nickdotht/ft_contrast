/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:09:51 by qho               #+#    #+#             */
/*   Updated: 2016/10/17 14:32:03 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *lcopy;
	t_list *new;

	lcopy = NULL;
	new = NULL;
	if (lst)
		lcopy = lst;
	while (lcopy)
	{
		ft_lstadd(&new, f(lcopy));
		lcopy = lcopy->next;
	}
	ft_lstrev(&new);
	return (new);
}
