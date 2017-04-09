/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 13:37:11 by qho               #+#    #+#             */
/*   Updated: 2016/10/17 13:58:34 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	list = NULL;
	if (alst == NULL)
		return ;
	list = *alst;
	if (list)
	{
		del(list->content, list->content_size);
		free(list);
	}
	*alst = NULL;
}
