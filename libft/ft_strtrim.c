/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 21:06:10 by qho               #+#    #+#             */
/*   Updated: 2016/10/17 14:05:43 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*ret;
	int		str;
	int		end;
	int		j;

	ret = NULL;
	j = 0;
	str = 0;
	if (s)
	{
		end = ft_strlen(s) - 1;
		str = find_start(str, s);
		end = find_end(end, s);
		ret = (char *)malloc(sizeof(char) * (ft_absolute_val(end - str) + 1));
		if (ret)
		{
			while (str < end)
				ret[j++] = s[str++];
			ret[j] = '\0';
		}
	}
	return (ret);
}
