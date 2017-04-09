/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:54 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 11:12:25 by qho              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONTRAST_H
# define FT_CONTRAST_H

# include <libft.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFF_SIZE 32

typedef struct		s_contrast
{
	char		*iname;
	char		*oname;
	float		contrast;
}					t_contrast;

typedef struct		s_header
{
	char		*p;
	int			width;
	int			height;
	int			maxgrey;
}					t_header;

void	ft_parseflags(char **input, t_contrast *data);
char	*ft_savefile(t_contrast *data, t_header *header);
void	ft_getheader(char **pgm, t_header *header);
void	ft_make_o(char *pgm, t_header *header, t_contrast *flags);




#endif