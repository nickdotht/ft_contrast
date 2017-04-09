/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 19:52:28 by qho               #+#    #+#             */
/*   Updated: 2016/09/25 18:10:19 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *s1a;
	unsigned char *s2a;

	s1a = (unsigned char *)s1;
	s2a = (unsigned char *)s2;
	while (n)
	{
		if (*s1a == *s2a)
		{
			s1a++;
			s2a++;
		}
		else
			return (*s1a - *s2a);
		n--;
	}
	return (0);
}
