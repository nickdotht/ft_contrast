/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 10:56:06 by qho               #+#    #+#             */
/*   Updated: 2016/10/17 14:30:01 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	new = (t_list*)malloc(sizeof(t_list));
	if (content)
	{
		if (new)
		{
			new->content = malloc(content_size);
			if (new->content)
			{
				ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
				new->next = NULL;
			}
		}
	}
	else
	{
		new->content = NULL;
		new->content_size = 0;
		new->next = NULL;
	}
	return (new);
}
