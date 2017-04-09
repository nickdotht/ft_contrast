/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:22:33 by qho               #+#    #+#             */
/*   Updated: 2017/04/05 11:35:24 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, char const *src, size_t len)
{
	char *dst2;

	dst2 = dst;
	while (len && *src)
	{
		*dst2++ = *src++;
		len--;
	}
	while (len)
	{
		*dst2++ = '\0';
		len--;
	}
	return (dst);
}
