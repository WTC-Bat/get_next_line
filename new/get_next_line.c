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

static int	fill_buff(const int fd, char *buff)
{
	int		cnt;

	cnt = 0;
	while (cnt < (BUFF_SIZE - 1))
	{
		read(fd, &buff[cnt], 1);
		if (buff[cnt] == '\n')	// if (ft_indexof(buff, '\n') == 1)
			return (1);
		else if (buff[cnt] == '\0')	//May not always get checked
			return (0);
		cnt++;
	}
	return (42);
}

int			get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE];
	int		status;

	status = 42;
	while (status != 0 && status != 1)	//&& status != -1 ?
	{
		ft_memset(buff, 0, BUFF_SIZE);
		status = fill_buff(fd, &buff[0]);
		if (ft_indexof(buff, '\n') > -1)
			status = 1;
	}
	return (status);
}

/*
**	T1
*/

// #include "get_next_line.h"
//
// static void	fill_buff(const int fd, char *buff)
// {
// 	int		cnt;
//
// 	cnt = 0;
// 	while (cnt < (BUFF_SIZE - 1))
// 	{
// 		read(fd, &buff[cnt], 1);
// 		if (buff[cnt] == '\n')	// if (ft_indexof(buff, '\n') == 1)
// 			break;
// 		cnt++;
// 	}
// }
//
// int		get_next_line(const int fd, char **line)
// {
// 	char	buff[BUFF_SIZE];
// 	int		status;
// 	int		line_read;
//
// 	status = 1;
// 	line_read = 0;
// 	// while (ft_indexof(buff, '\n') == -1)
// 	while (line_read == 0)
// 	{
// 		ft_memset(buff, 0, BUFF_SIZE);
// 		fill_buff(fd, &buff[0]);
// 		if (ft_indexof(buff, '\n') > -1)
// 			line_read = 1;
// 	}
// 	return (42);
// }

/*Basic Idea*/

// int		get_next_line(const int fd, char **line)
// {
// 	char	buff[BUFF_SIZE];
// 	char	*l;
// 	int		cnt;
//
// 	cnt = 0;
// 	line = NULL;
// 	ft_memset(buff, 0, BUFF_SIZE);
// 	while (cnt < BUFF_SIZE - 1)
// 	{
// 		read(fd, &buff[cnt], 1);
// 		cnt++;
// 	}
// 	return (42);
// }
