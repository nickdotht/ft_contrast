/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/09 20:52:59 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 20:56:01 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_contrast.h"

void	line_handler(int *fd, char *line, t_flags flags, char *next)
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

void	image_handler(int *fd, t_header header, t_flags flags)
{
	char	**lines;
	int		fd2;
	int		i;

	(void)header;
	if ((fd2 = open(flags.oname, O_CREAT | O_WRONLY | O_TRUNC, 0666)) == -1)
		ft_error("Could not create output file", 2);
	dprintf(fd2, "P2\n%d %d\n%d\n", header.width, header.height,
		header.maxgrey);
	i = -1;
	lines = (char **)ft_memalloc(sizeof(char *));
	while (get_next_line(*fd, &lines[++i]) != 0)
		;
	i = -1;
	while (lines[++i])
		line_handler(&fd2, lines[i], flags, lines[i + 1]);
}

int		header_handler(t_flags flags, t_header *header)
{
	int		i;
	char	*line;
	int		fd;
	char	**size;

	i = -1;
	if ((fd = open(flags.iname, O_RDONLY)) == -1)
		ft_error("Could not open input file", 1);
	while (++i < 3)
	{
		get_next_line(fd, &line);
		if (i == 0 && (!ft_strequ(line, "P2")))
			ft_error("Only P2 type pgm files accepted", 2);
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
