/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrameau <jrameau@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:54 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 21:22:46 by jrameau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H

# include <libft.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <pthread.h>

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
