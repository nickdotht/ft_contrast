/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:03:15 by qho               #+#    #+#             */
/*   Updated: 2016/10/12 10:37:08 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	j;

	ret = NULL;
	i = 0;
	j = (size_t)start;
	if (s)
		ret = (char *)malloc((sizeof(char) * len) + 1);
	if (ret)
	{
		while (len)
		{
			ret[i++] = s[j++];
			len--;
		}
		ret[i] = '\0';
	}
	return (ret);
}
