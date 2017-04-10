/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <jrameau@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 15:29:09 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 20:13:32 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

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

void line_handler(int *fd, char *line, t_flags flags, char *next)
{
	int nb;
	
	while (*line)
	{
		if (IS_SPACE(*line))
			dprintf(*fd, "%c", *line);
		else if (*line == '0')
			dprintf(*fd, "0");
		else if (*line >= '1' && *line <= '9')
		{
			nb = ft_atoi(line);
			dprintf(*fd, "%.0f", (nb * flags.contrast));
			line += ft_intlen(nb) - 1;
		}
		line++;
	}
	if (next)
		dprintf(*fd, "\n");
}

void image_handler(int *fd, t_header header, t_flags flags)
{
	char **lines;
	int fd2;
	int i;

	(void)header;
	if ((fd2 = open(flags.oname, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
	{
		dprintf(2, "Couldn't create '%s'", flags.oname);
		exit(2);
	}
	dprintf(fd2, "P2\n%d %d\n%d\n", header.width, header.height, header.maxgrey);
	i = -1;
	lines  = (char **)ft_memalloc(sizeof(char *));
	while (get_next_line(*fd, &lines[++i]) != 0)
		;
	i = -1;
	while (lines[++i])
		line_handler(&fd2, lines[i], flags, lines[i + 1]);
}

int header_handler(t_flags flags, t_header *header)
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
		flag_handler(av, &flags);
		fd = header_handler(flags, &header);
		image_handler(&fd, header, flags);
		close(fd);
	}
	else
		printf("usage: ft_contrast -f [inputfile] -c [contrast_val(0-100)] -o [outputfile]\n");
}
