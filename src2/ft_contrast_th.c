/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast_th.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <jrameau@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:29:09 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 23:35:59 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast_th.h"

void	flag_handler_th(char **input, t_flags *flags)
{
	int i;

	i = 1;
	while (input[i])
	{
		if (ft_strcmp(input[i], "-f") == 0 && !flags->iname)
			flags->iname = input[++i];
		else if (ft_strcmp(input[i], "-c") == 0 && !flags->contrast)
		{
			flags->contrast = (float)ft_atoi(input[++i])/100;
			if (flags->contrast < 0 || flags->contrast > 100)
			{
				printf("Invalid -c value, please use a value from 0 to 100\n");
				exit(1);
			}
		}
		else if (ft_strcmp(input[i], "-o") == 0 && !flags->oname)
			flags->oname = input[++i];
		else
			printf("Some invalid input\n");
		i++;
	}

}

void *line_handler_th(void *arg)
{
	int nb;
	t_line *line = (t_line *)arg;
	int j;
	int max;
	
	max = line->idx + 64;
	while (line->idx++ < max)
	{
		j = -1;
		while (**(line->lines))
		{
			if (IS_SPACE(**line->lines))
				dprintf(line->fd, "%c", **line->lines);
			else if (**(line->lines) == '0')
				dprintf(line->fd, "0");
			else if (**(line->lines) >= '1' && **(line->lines) <= '9')
			{
				nb = ft_atoi(*(line->lines));
				dprintf(line->fd, "%.0f", (nb * line->flags.contrast));
				*(line->lines) += ft_intlen(nb) - 1;
			}
			*(line->lines) += 1;
		}
		// if (next)
		// 	dprintf(line->fd, "\n");
	}
	return (NULL);
}

void image_handler_th(int *fd, t_header header, t_flags flags)
{
	t_line line;
	t_line *lines;
	pthread_t *tid;
	int i;
	int j;
	
	tid = (pthread_t *)ft_memalloc( NUM_THREADS * sizeof(pthread_t) );
	if ((line.fd = open(flags.oname, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
	{
		dprintf(2, "Couldn't create '%s'", flags.oname);
		exit(2);
	}
	dprintf(line.fd, "P2\n%d %d\n%d\n", header.width, header.height, header.maxgrey);
	line.idx = -1;
	line.lines  = (char **)ft_memalloc(sizeof(char *));
	while (get_next_line(*fd, &line.lines[++line.idx]) != 0)
		;
	line.idx = 0;
	line.flags = flags;
	i = -1;
	lines = (t_line *)ft_memalloc(sizeof(t_line) * 64);
	while (line.lines[line.idx])
	{
		lines[++i].fd = line.fd;
		lines[i].lines = line.lines;
		lines[i].flags = line.flags;
		lines[i].idx = line.idx;
		pthread_create(&tid[i], NULL, line_handler_th, &lines[i]);
		line.lines += 64;
		line.idx += 64;
	}
	j = 0;
	while (line.lines[j])
		pthread_join( tid[j++], NULL);
}

int header_handler_th(t_flags flags, t_header *header)
{
	int i;
	char *line;
	int fd;
	char **size;

	i = -1;
	if ((fd = open(flags.iname, O_RDONLY)) == -1)
	{
		dprintf(2, "Couldn't read '%s'\n", flags.iname);
		exit(2);
	}
	while (++i < 3)
	{
		get_next_line(fd, &line);
		if (i == 0)
		{
			if (!ft_strequ(line, "P2"))
			{
				dprintf(2, "Only P2 pgm files allowed\n");
				exit(1);
			}
		}
		else if (i == 1)
		{
			size = ft_strsplit(line, ' ');
			header->width = ft_atoi(size[0]);
			header->height = ft_atoi(size[1]);
		}
		else
			header->maxgrey = ft_atoi(line);
		free(line);
	}
	return (fd);
}

int	main(int ac, char **av)
{
	t_flags	flags;
	t_header	header;
	int			fd;

	if (ac == 7)
	{
		flag_handler_th(av, &flags);
		fd = header_handler_th(flags, &header);
		image_handler_th(&fd, header, flags);
		close(fd);
	}
	else
		printf("usage: ft_contrast -f [inputfile] -c [contrast_val(0-100)] -o [outputfile]\n");
}
