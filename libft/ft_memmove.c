/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 16:58:49 by qho               #+#    #+#             */
/*   Updated: 2016/09/28 17:36:02 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst2;
	unsigned char	*src2;

	dst2 = (unsigned char *)dst;
	src2 = (unsigned char *)src;
	if (src2 < dst2)
	{
		src2 = src2 + len - 1;
		dst2 = dst2 + len - 1;
		while (len > 0)
		{
			*dst2-- = *src2--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*dst2++ = *src2++;
			len--;
		}
	}
	return (dst);
}
