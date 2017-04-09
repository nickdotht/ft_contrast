/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 18:30:57 by qho               #+#    #+#             */
/*   Updated: 2017/01/06 14:50:57 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		i;
	int		j;

	ret = NULL;
	i = 0;
	j = 0;
	if (s1 && s2)
		ret = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret)
	{
		while (s1[i] != '\0')
		{
			ret[i] = s1[i];
			i++;
		}
		while (s2[j] != '\0')
		{
			ret[i] = s2[j];
			i++;
			j++;
		}
		ret[i] = '\0';
	}
	return (ret);
}
