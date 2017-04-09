/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:15:02 by qho               #+#    #+#             */
/*   Updated: 2016/10/15 22:38:25 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	char	*s;
	size_t	n;
	size_t	dlen;

	d = dst;
	s = (char *)src;
	n = size;
	while ((n != 0) && (*d != '\0'))
	{
		d++;
		n--;
	}
	dlen = d - dst;
	if (n == 0)
		return (dlen + (ft_strlen(src)));
	while ((n - 1 != 0) && *s != '\0')
	{
		*d++ = *s++;
		n--;
	}
	*d = '\0';
	if (n - 1 == 0)
		return (dlen + (ft_strlen(src)));
	return (dlen + (s - src));
}
