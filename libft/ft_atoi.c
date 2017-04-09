/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/08 17:26:08 by qho               #+#    #+#             */
/*   Updated: 2017/03/15 07:07:33 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countspace(const char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '+'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

static int	ft_signs(const char *str, int len)
{
	int cnt;
	int i;

	i = 0;
	cnt = 0;
	while (i < len)
	{
		if (str[i] == '+')
			cnt++;
		i++;
	}
	return (cnt);
}

int			ft_atoi(const char *str)
{
	unsigned int	i;
	int				sign;
	int				ans;
	int				plus;

	i = ft_countspace(str);
	ans = 0;
	sign = 1;
	plus = ft_signs(str, i);
	if (plus < 2)
	{
		if (str[i] == '-' && plus == 0)
		{
			sign = -1;
			i++;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			ans = ans * 10;
			ans = ans + (str[i] - '0');
			i++;
		}
	}
	return (sign * ans);
}
