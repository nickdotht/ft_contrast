/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:37:29 by qho               #+#    #+#             */
/*   Updated: 2017/04/08 16:28:23 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	i = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	if (s1a[i] == '\0')
		return (s1a[i] - s2a[i]);
	while (s1a[i] != '\0' || s2a[i] != '\0')
	{
		if (s2a[i] == '\0')
			return (s1a[i]);
		else if (s2a[i] != s1a[i])
			return (s1a[i] - s2a[i]);
		i++;
	}
	return (0);
}
