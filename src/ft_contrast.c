/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:29:09 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 12:10:28 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

void	ft_parseflags(char **input, t_contrast *data)
{
	int i;

	i = 1;
	while (input[i])
	{
		if (ft_strcmp(input[i], "-f") == 0 && !data->iname)
			data->iname = input[++i];
		else if (ft_strcmp(input[i], "-c") == 0 && !data->contrast)
		{
			data->contrast = (float)ft_atoi(input[++i])/100;
			if (data->contrast < 0 || data->contrast > 100)
			{
				printf("Invalid -c value, please use a value from 0 to 100\n");
				exit(1);
			}
		}
		else if (ft_strcmp(input[i], "-o") == 0 && !data->oname)
			data->oname = input[++i];
		else
			printf("Some invalid input\n");
		i++;
	}

}

char	*ft_savefile(t_contrast *data, t_header *header)
{
	int			fd;
	char		*buf;
	char		*pgm;
	int			ret;

	(void) header;
	if ((fd = open(data->iname, O_RDONLY)) != -1)
		buf = (char *)malloc(sizeof(char) + (BUFF_SIZE + 1));
	else
	{
		printf("There was an error reading '%s'", data->iname);
		exit(2);
	}
	pgm = ft_strnew(BUFF_SIZE + 1);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!pgm)
			ft_strcpy(pgm, buf);
		else
			pgm = ft_strjoin(pgm, buf);
	}
	close(fd);
	return (pgm);
}

int		ft_numlen(int	nb)
{
	int	len;

	len = 0;
	while (nb)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void	ft_getheader(char **pgm, t_header *header)
{
	char	*tmp;
	int		i;

	i = -1;
	tmp = *pgm;
	if (tmp[0] == 'P' && tmp[1] == '2')
	{
		header->p = (char*)malloc(sizeof(char) * 3);
		header->p = ft_strncpy(header->p, tmp, 2);
		tmp += 2;
	}	
	while (*tmp)
	{
		if (*tmp == ' ' || *tmp == '\n')
			tmp++;
		if ((*tmp >= '0' && *tmp <= '9') && !header->width)
		{
			header->width = ft_atoi(tmp);
			tmp += ft_numlen(header->width);
		}
		if ((*tmp >= '0' && *tmp <= '9') && !header->height)
		{
			header->height = ft_atoi(tmp);
			tmp += ft_numlen(header->height);
		}
		if ((*tmp >= '0' && *tmp <= '9') && !header->maxgrey)
		{
			header->maxgrey = ft_atoi(tmp);
			tmp += ft_numlen(header->maxgrey);
		}
		if (header->width && header->height && header->maxgrey)
			break ;
		tmp++;
	}
	*pgm = tmp;
}

void	ft_make_o(char *pgm, t_header *header, t_contrast *flags)
{
	int		fd;
	char	*tmp;
	int		nb;

	tmp = pgm;
	if ((fd = open(flags->oname, O_CREAT | O_WRONLY | O_TRUNC, 0666)) != -1)
	{
		dprintf(fd, "%s\n%d %d\n%d", header->p, header->width, header->height, header->maxgrey);
		while (*tmp)
		{
			if (*tmp == ' ' || *tmp == '\n')
				dprintf(fd, "%c", *tmp);
			else if (*tmp == '0')
				dprintf(fd, "0");
			else if (*tmp >= '1' && *tmp <= '9')
			{
				nb = ft_atoi(tmp);
				dprintf(fd, "%.0f", (nb * flags->contrast));
				tmp += ft_numlen(nb) - 1;
			}
			tmp++;
		}
	}
	printf("file written?\n");
}

int	main(int ac, char **av)
{
	t_contrast	data;
	t_header	header;
	char		*pgm;

	if (ac == 7)
	{
		ft_parseflags(av, &data);
		pgm = ft_savefile(&data, &header);
		ft_getheader(&pgm, &header);
		ft_make_o(pgm, &header, &data);
	}
	else
		printf("usage: ft_contrast -f [inputfile] -c [contrast_val(0-100)] -o [outputfile]\n");
}
