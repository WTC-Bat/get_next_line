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

static char	*read_line(const int fd, t_fd **tfd, int *status)
{
	char	*line;
	size_t	len;
	size_t	cnt;
	size_t	tpos;

	cnt = 0;
	len = 0;
	tpos = 0;
	while ((*tfd) != NULL)
	{
		ft_putendl("LOOP");
		if ((*tfd)->fd == fd)
		{
			ft_putendl("MATCH");
			tpos = (*tfd)->pos;
			while ((*tfd)->text[tpos] != '\n' && (*tfd)->text[tpos] != '\0')
			{
				tpos++;
				len++;
			}
			if ((*tfd)->text[tpos] != '\n')
				*status = 1;
			if ((*tfd)->text[tpos] != '\0')
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
		(*tfd) = (*tfd)->next;
	}
 	return (NULL);
}

static char	*get_text(const int fd)
{
	char	buff[BUFF_SIZE];
	char	*text;

	// text = ft_strnew(BUFF_SIZE + 1);
	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
		return (NULL);
	ft_memset(buff, '\0', (size_t)BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		text = ft_strcat(text, buff);
		ft_memset(buff, '\0', (size_t)BUFF_SIZE);
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

static void	add_tfd(const int fd, t_fd *tfd)
{
	// char	*text;
	t_fd	*tmp;

	if ((tmp = (t_fd *)malloc(sizeof(t_fd))) == NULL)
		return ;
	if (tfd == NULL)
	{
		tmp->fd = fd;
		tmp->pos = 0;
		tmp->text = get_text(fd);
		tmp->next = NULL;
		tfd = tmp;
	}
	else
	{
		if (fd_in_struct(fd, tfd) == 0)
		{
			ft_putendl("NOT_IN_STRUCT");
			tmp->fd = fd;
			tmp->pos = 0;
			tmp->text = get_text(fd);
			// tmp->next = tfd;	//Puts the new element at the beginning
			while (tfd != NULL)
				tfd = tfd->next;
			tfd = tmp;
		}
	}
}

// static void	add_tfd(const int fd, t_fd *tfd)
// {
// 	// char	*text;
//
// 	if (tfd == NULL)
// 	{
// 		tfd->fd = fd;
// 		tfd->pos = 0;
// 		tfd->text = get_text(fd);
// 		tfd->next = NULL;
// 	}
// 	else
// 	{
// 		if (fd_in_struct(fd, tfd) == 0)
// 		{
// 			ft_putendl("NOT_IN_STRUCT");
// 			while (tfd != NULL)
// 				tfd = tfd->next;
// 			tfd->fd = fd;
// 			tfd->pos = 0;
// 			tfd->text = get_text(fd);
// 			tfd->next = NULL;
// 		}
// 	}
// }

// static void	add_tfd(const int fd, t_fd *tfd)
// {
// 	// char	*text;
//
// 	if (tfd != NULL)
// 		while (tfd != NULL)
// 			tfd = tfd->next;
// 	if ((tfd = (t_fd *)malloc(sizeof(t_fd))) != NULL)
// 	{
// 		tfd->fd = fd;
// 		tfd->pos = 0;
// 		tfd->text = get_text(fd);
// 		tfd->next = NULL;
// 	}
// }

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
	*line = read_line(fd, &tfd, &status);
	return (status);
}





/*ERRORING*/

// #include "get_next_line.h"
//
// static char	*read_line(const int fd, t_fd **tfd, int *status)
// {
// 	char	*line;
// 	size_t	len;
// 	size_t	cnt;
// 	size_t	tpos;
//
// 	if ((line = (char *)malloc(sizeof(char) * len)) == NULL)	//+1?
// 		return (NULL);
// 	cnt = 0;
// 	len = 0;
// 	tpos = 0;
// 	while ((*tfd) != NULL)
// 	{
// 		if ((*tfd)->fd == fd)
// 		{
// 			tpos = (*tfd)->pos;
// 			while ((*tfd)->text[tpos] != '\n' && (*tfd)->text[tpos] != '\0')
// 			{
// 				tpos++;
// 				len++;
// 			}
// 			if ((*tfd)->text[tpos] != '\n')
// 				*status = 1;
// 			if ((*tfd)->text[tpos] != '\0')
// 				*status = 0;
// 			while (cnt < len)
// 			{
// 				line[cnt] = (*tfd)->text[(*tfd)->pos];
// 				cnt++;
// 				(*tfd)->pos++;
// 			}
// 			line[cnt] = '\0';
// 			return (line);
// 		}
// 		(*tfd) = (*tfd)->next;
// 	}
//  	return (NULL);
// }
//
// static char	*get_text(const int fd)
// {
// 	char	buff[BUFF_SIZE];
// 	char	*text;
//
// 	// text = ft_strnew(BUFF_SIZE + 1);
// 	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
// 		return (NULL);
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
// 	while (*tfd != NULL)
// 	{
// 		if ((*tfd)->fd == fd)
// 			return (1);
// 		*tfd = (*tfd)->next;
// 	}
// 	return (0);
// }
//
// static void	add_tfd(const int fd, t_fd *tfd)
// {
// 	char	*text;
// 	t_fd	*tmp;
//
// 	if ((tmp = (t_fd *)malloc(sizeof(t_fd))) != NULL)
// 	{
// 		// text = get_text(fd);
// 		tmp->fd = fd;
// 		tmp->pos = 0;
// 		// tmp->text = ft_strdup(text);
// 		tmp->text = get_text(fd);
// 		tmp->next = tfd;
// 		tfd = tmp;
// 		// ft_strdel(&text);
// 	}
// }
//
// 			// static void	add_tfd(const int fd, t_fd **tfd)
// 			// {
// 			// 	char	*text;
// 			//
// 			// 	while ((*tfd) != NULL)
// 			// 		(*tfd) = (*tfd)->next;
// 			// 	if (((*tfd) = (t_fd *)malloc(sizeof(tfd))) != NULL)
// 			// 	{
// 			// 		text = get_text(fd);
// 			// 		(*tfd)->fd = fd;
// 			// 		(*tfd)->pos = 0;
// 			// 		(*tfd)->text = ft_strdup(text);
// 			// 		(*tfd)->next = NULL;
// 			// 	}
// 			// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	static t_fd	*tfd;
// 	int			status;
//
// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	status = 42;
// 	// tfd = NULL;
// 	if (tfd == NULL || fd_in_struct(fd, &tfd) == 0)
// 	{
// 		ft_putendl("NOT_IN_STRUCT");
// 		add_tfd(fd, tfd);
// 		ft_putendl("ADDED");
// 	}
// 	else
// 	{
// 		ft_putendl("IN_STRUCT");
// 	}
// 	ft_putendl("READING");
// 	*line = read_line(fd, &tfd, &status);
// 	return (status);
// }
