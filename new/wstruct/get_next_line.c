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

/*ERRORING*/

#include "get_next_line.h"

tatic char	*read_line(const int fd, t_fd **tfd, int *status)
{
	char	*line;
	size_t	len;
	size_t	cnt;

	cnt = 0;
	len = 0;
	while ((*tfd) != NULL)
	{
		if ((*tfd)->fd == fd)
		{
			while ((*tfd)->text[len] != '\n' && (*tfd)->text[len] != '\0')
				len++;
			if ((*tfd)->text[len] != '\n')
				*status = 1;
			if ((*tfd)->text[len] != '\0')
				*status = 0;
			if ((line = (char *)malloc(sizeof(char) * len)) == NULL)	//+1?
				return (NULL);
			while (cnt < len)
			{
				line[cnt] = (*tfd)->text[(*tfd)->pos];
				cnt++;
				(*tfd)->pos++;
			}
			line[cnt] = '\0';
			return (line);
		}
	}
	return (NULL);
}

static char	*get_text(const int fd)
{
	char	buff[BUFF_SIZE];
	char	*text;

	text = ft_strnew(BUFF_SIZE + 1);
	ft_memset(buff, '\0', (size_t)BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		text = ft_strcat(text, buff);
		ft_memset(buff, '\0', (size_t)BUFF_SIZE);
	}
	return (text);
}

static int	fd_in_struct(const int fd, t_fd **tfd)
{
	while ((*tfd) != NULL)
	{
		if ((*tfd)->fd == fd)
			return (1);
		(*tfd) = (*tfd)->next;
	}
	return (0);
}

static void	add_tfd(const int fd, t_fd **tfd)
{
	char	*text;

	while ((*tfd) != NULL)
		(*tfd) = (*tfd)->next;
	if (((*tfd) = (t_fd *)malloc(sizeof(tfd))) != NULL)
	{
		(*tfd)->fd = fd;
		(*tfd)->pos = 0;
		(*tfd)->text = get_text(fd);
		(*tfd)->next = NULL;
	}
}

int			get_next_line(const int fd, char **line)
{
	static t_fd	*tfd;
	int			status;

	if (fd < 0 || line == NULL)
		return (-1);
	status = 42;
	tfd = NULL;
	if (fd_in_struct(fd, &tfd) == 0)
		add_tfd(fd, &tfd);
	*line = read_line(fd, &tfd, &status);
	return (status);
}




/*???*/

// static char	*read_line(const int fd, t_fd **tfd, int *status)
// {
// 	char	*line;
// 	size_t	len;
// 	size_t	cnt;
//
// 	cnt = 0;
// 	len = 0;
// 	while ((*tfd) != NULL)
// 	{
// 		if ((*tfd)->fd == fd)
// 		{
// 			while ((*tfd)->text[len] != '\n' && (*tfd)->text[len] != '\0')
// 				len++;
// 			if ((*tfd)->text[len] != '\n')
// 				*status = 1;
// 			if ((*tfd)->text[len] != '\0')
// 				*status = 0;
// 			if ((line = (char *)malloc(sizeof(char) * len)) == NULL)	//+1?
// 				return (NULL);
// 			while (cnt < len)
// 			{
// 				line[cnt] = (*tfd)->text[(*tfd)->pos];
// 				cnt++;
// 				(*tfd)->pos++;
// 			}
// 			line[cnt] = '\0';
// 			return (line);
// 		}
// 	}
// 	return (NULL);
// }
//
// static char	*get_text(const int fd)
// {
// 	char	buff[BUFF_SIZE];
// 	char	*text;
//
// 	text = ft_strnew(BUFF_SIZE + 1);
// 	ft_memset(buff, '\0', (size_t)BUFF_SIZE);
// 	while (read(fd, buff, BUFF_SIZE - 1) > 0)
// 	{
// 		text = ft_strcat(text, buff);
// 		ft_memset(buff, '\0', (size_t)BUFF_SIZE);
// 	}
// 	return (text);
// }
//
// static int	fd_in_struct(const int fd, t_fd **tfd)
// {
// 	while ((*tfd) != NULL)
// 	{
// 		if ((*tfd)->fd == fd)
// 			return (1);
// 		(*tfd) = (*tfd)->next;
// 	}
// 	return (0);
// }
//
// static void	add_tfd(const int fd, t_fd **tfd)
// {
// 	char	*text;
//
// 	while ((*tfd) != NULL)
// 		(*tfd) = (*tfd)->next;
// 	if (((*tfd) = (t_fd *)malloc(sizeof(tfd))) != NULL)
// 	{
// 		(*tfd)->fd = fd;
// 		(*tfd)->pos = 0;
// 		(*tfd)->text = get_text(fd);
// 		(*tfd)->next = NULL;
// 	}
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	static t_fd	*tfd;
// 	int			status;
//
// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	status = 42;
// 	tfd = NULL;
// 	if (fd_in_struct(fd, &tfd) == 0)
// 		add_tfd(fd, &tfd);
// 	*line = read_line(fd, &tfd, &status);
// 	return (status);
// }
