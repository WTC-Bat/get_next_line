/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/17 13:02:48 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/06/07 14:35:08 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 32

typedef struct	s_fd
{
	int			fd;
	// int			pos;
	size_t		pos;
	char		*text;
	struct s_fd	*next;
}				t_fd;

// typedef struct	s_fd
// {
// 	int			fd;
// 	int			line_pos;
// 	char		**lines;
// 	t_fd		*next;
// }				t_fd;

int		get_next_line(const int fd, char **line);

#endif
