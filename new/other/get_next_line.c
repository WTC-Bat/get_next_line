/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 15:04:06 by mlamarre          #+#    #+#             */
/*   Updated: 2016/06/07 14:49:01 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	-1	:	Error
**	 0	:	All lines read. Complete
**	 1	:	Single line read
*/

#include "get_next_line.h"

static char	*get_text(const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*text;

	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (NULL);
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		text = ft_strcat(text, buff);
		ft_memset(buff, '\0', BUFF_SIZE + 1);
	}
	return (text);
}

static int	fd_in_struct(const int fd, t_fd *tfd)
{
	while (tfd != NULL)
	{
		if (tfd->fd == fd)
			return (1);
		tfd = tfd->next;
	}
	return (0);
}

static void	add_tfd(const int fd, t_fd **tfd)
{
	t_fd	*tmp;

	if ((tmp = (t_fd *)malloc(sizeof(t_fd))) != NULL)
	{
		if (fd_in_struct(fd, *tfd) == 0)
		{
			tmp->fd = fd;
			tmp->pos = 0;
			tmp->text = get_text(fd);
			tmp->next = NULL;
			if (tfd == NULL)
				*tfd = tmp;
			else
				tmp->next = *tfd;
		}
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_fd	*tfd;
	int			status;

	if (fd < 0 || line == NULL)
		return (-1);
	status = 42;
	if (!tfd)
		tfd = NULL;
	ft_putendl("ADDING");
	add_tfd(fd, &tfd);
	ft_putendl("READING");
	ft_putendl(tfd->text);
	// *line = read_line(fd, &tfd, &status);
	return (status);
}
