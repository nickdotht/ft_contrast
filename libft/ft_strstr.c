/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 16:05:11 by qho               #+#    #+#             */
/*   Updated: 2016/10/10 16:40:13 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*str;
	char	*match;

	if (!*little)
		return ((char *)big);
	while (*big)
	{
		if (*big == *little)
		{
			str = (char *)big;
			match = (char *)little;
			while (*str && *match && *str == *match)
			{
				str++;
				match++;
			}
			if (!*match)
				return ((char *)big);
		}
		big++;
	}
	return (0);
}
