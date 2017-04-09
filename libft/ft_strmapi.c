/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 20:53:35 by qho               #+#    #+#             */
/*   Updated: 2016/10/12 10:28:06 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	int		i;

	ret = NULL;
	i = 0;
	if (s)
		ret = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (ret)
	{
		while (s[i])
		{
			ret[i] = (char)f(i, s[i]);
			i++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
