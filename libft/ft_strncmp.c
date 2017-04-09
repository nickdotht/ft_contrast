/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:52:14 by qho               #+#    #+#             */
/*   Updated: 2016/10/13 11:13:42 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned char	*s1a;
	unsigned char	*s2a;

	i = 0;
	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	if (s1a[i] == '\0')
		return (s1a[i] - s2a[i]);
	while ((s1a[i] != '\0' || s2a[i] != '\0') && n)
	{
		if (s2a[i] == '\0')
			return (s1a[i]);
		else if (s2a[i] != s1a[i])
			return (s1a[i] - s2a[i]);
		i++;
		n--;
	}
	return (0);
}
