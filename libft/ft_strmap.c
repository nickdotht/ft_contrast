/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 20:26:01 by qho               #+#    #+#             */
/*   Updated: 2016/10/12 10:27:28 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	int		i;

	i = 0;
	ret = NULL;
	if (s)
		ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret)
	{
		while (s[i])
		{
			ret[i] = (char)f(s[i]);
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
