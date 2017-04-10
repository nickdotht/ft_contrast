/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:29:09 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 20:57:50 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

void	ft_error(char *str, int error)
{
	dprintf(2, "%s\n", str);
	exit(error);
}

void	flag_handler(char **input, t_flags *flags)
{
	int i;

	i = 1;
	while (input[i])
	{
		if (ft_strcmp(input[i], "-f") == 0 && !flags->iname)
			flags->iname = input[++i];
		else if (ft_strcmp(input[i], "-c") == 0 && !flags->contrast)
		{
			flags->contrast = (float)ft_atoi(input[++i]) / 100;
			if (flags->contrast < 0 || flags->contrast > 100)
				ft_error("Invalid -c value, use a value from 0 to 100", 1);
		}
		else if (ft_strcmp(input[i], "-o") == 0 && !flags->oname)
			flags->oname = input[++i];
		else
			printf("Some invalid input\n");
		i++;
	}
}

int		main(int ac, char **av)
{
	t_flags		flags;
	t_header	header;
	int			fd;

	if (ac == 7)
	{
		flag_handler(av, &flags);
		fd = header_handler(flags, &header);
		image_handler(&fd, header, flags);
		close(fd);
	}
	else
		printf("usage: ft_contrast -f [input] -c [%%val] -o [output]\n");
}
