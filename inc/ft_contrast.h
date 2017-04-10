/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:54 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 21:14:37 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct		s_flags
{
	char		*iname;
	char		*oname;
	float		contrast;
}					t_flags;

typedef struct		s_header
{
	int			width;
	int			height;
	int			maxgrey;
}					t_header;

void	ft_error(char *str, int error);
void	flag_handler(char **input, t_flags *flags);
void	line_handler(int *fd, char *line, t_flags flags, char *next);
void	image_handler(int *fd, t_header header, t_flags flags);
int		header_handler(t_flags flags, t_header *header);

#endif
