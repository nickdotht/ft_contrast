/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 16:04:58 by qho               #+#    #+#             */
/*   Updated: 2016/10/17 13:53:51 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	find_little(char *str, char *find, int i, size_t len)
{
	while (len && *str && *find && *str == *find)
	{
		str++;
		find++;
		i++;
		len--;
	}
	len += i;
	if (!*find)
		return (0);
	return (1);
}

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	*str;
	char	*find;
	int		i;

	if (!*little)
		return ((char *)big);
	while (len && *big)
	{
		i = 0;
		if (*big == *little)
		{
			str = (char *)big;
			find = (char *)little;
			if (find_little(str, find, i, len) == 0)
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (0);
}
