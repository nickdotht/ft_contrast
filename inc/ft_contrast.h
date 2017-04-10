/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_contrast.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qho <qho@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/08 17:01:54 by qho               #+#    #+#             */
/*   Updated: 2017/04/09 20:37:55 by qho              ###   ########.fr       */
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

#endif