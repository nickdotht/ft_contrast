/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 14:29:56 by qho               #+#    #+#             */
/*   Updated: 2016/10/08 15:20:55 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst2;
	unsigned char *src2;
	unsigned char x;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	x = (unsigned char)c;
	while (n)
	{
		if ((*dst2++ = *src2++) == x)
			return (dst2);
		n--;
	}
	return (0);
}
