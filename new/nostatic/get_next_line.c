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

static void	free_lines(char **lines)
{
	int		cnt;

	cnt = 0;
	while (lines[cnt] != NULL)
	{
		ft_strdel(&lines[cnt]);
		cnt++;
	}
}

static int	fill_buff(const int fd, char *buff)
{
	int		cnt;
	int		status;

	cnt = 0;
	status = 42;
	while (cnt < BUFF_SIZE - 1)
	{
		read(fd, &buff[cnt], 1);
		if (buff[cnt] == '\n')
		{
			buff[cnt] = '\0';
			return (1);
		}
		if (buff[cnt] == '\0')
			return (0);
		cnt++;
	}
	buff[cnt] = '\0';
	return (42);
}

int			get_next_line(const int fd, char **line)
{
	char		*l;
	char		buff[BUFF_SIZE];
	int			status;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	if ((l = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		return (-1);
	status = 42;
	while (status == 42)
	{
		// ft_memset(buff, '\0', BUFF_SIZE);

		status = fill_buff(fd, &buff[0]);
		l = ft_strcat(l, buff);
	}
	*line = ft_strdup(l);
	ft_strdel(&l);
	return (status);
}
