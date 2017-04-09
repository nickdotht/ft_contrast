/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 19:20:15 by qho               #+#    #+#             */
/*   Updated: 2017/03/09 12:20:34 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memdel(void **ap)
{
	char	**cp;
	int		i;
	int		j;

	cp = NULL;
	i = 0;
	j = 0;
	if (ap == NULL)
		return ;
	cp = (char **)ap;
	while (*cp[i])
	{
		while (cp[j])
		{
			free(cp[j]);
			j++;
		}
		cp = NULL;
		free(cp[i]);
		i++;
	}
	*cp = NULL;
}
