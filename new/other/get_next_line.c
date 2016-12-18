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

static char	*read_line(t_fd *tfd)
{
	char	*line;
	size_t	len;
	size_t	idx;

	len = 0;
	idx = tfd->pos;
	while (tfd->text[idx] != '\0' && tfd->text[idx] != '\n')
	{
		len++;
		idx++;
	}
	if (len == 0 || (tfd->pos == (ft_strlen(tfd->text))))	//-1?
		return (NULL);
	//Check length is not past end
	line = ft_strsub(tfd->text, tfd->pos, len);
	tfd->pos = idx + 1;	//+ 1?
	return (line);
}

static char	*get_text(const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*text;

	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (NULL);
	ft_memset(buff, '\0', BUFF_SIZE + 1);
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if (text[0] == '\0')
			text = ft_strdup(buff);
		else
			text = ft_strcat(text, buff);
		ft_memset(buff, '\0', BUFF_SIZE + 1);
	}
	return (text);
}

static void	add_tfd(const int fd, t_fd **tfd)
{
	t_fd	*new;

	if ((new = (t_fd *)malloc(sizeof(t_fd))) == NULL)
		return ;
	new->fd = fd;
	new->pos = 0;
	new->text = get_text(fd);
	new->next = (*tfd);
	(*tfd) = new;
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

int			get_next_line(const int fd, char **line)
{
	char		*text;
	static t_fd	*tfd = NULL;
	char		*l;
	int			status;

	status = 42;
	if (fd_in_struct(fd, tfd) == 0)
		add_tfd(fd, &tfd);
	while (tfd != NULL)
	{
		if (tfd->fd == fd)
			break;
		tfd = tfd->next;
	}
	ft_putendl(tfd->text);
	l = read_line(tfd);
	// ft_putendl(l);
	if (l == NULL)
		return (0);
	if (tfd->pos == (ft_strlen(tfd->text) - 1))
	{
		status = 0;
		//free tfd?
		ft_strdel(&(tfd)->text);
	}
	else
		status = 1;
	*line = l;
	ft_strdel(&l);
	return (status);
}






// #include "get_next_line.h"
//
// static char	*get_text(const int fd)
// {
// 	char	buff[BUFF_SIZE + 1];
// 	char	*text;
//
// 	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
// 		return (NULL);
// 	ft_memset(buff, '\0', BUFF_SIZE + 1);
// 	while (read(fd, buff, BUFF_SIZE) > 0)
// 	{
// 		if (text[0] == '\0')
// 			text = ft_strdup(buff);
// 		else
// 			text = ft_strcat(text, buff);
// 		ft_memset(buff, '\0', BUFF_SIZE + 1);
// 	}
// 	return (text);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	char	*text;
//
// 	text = get_text(fd);
// 	ft_putendl("TEXT:");
// 	ft_putendl(text);
// 	return (0);
// }
