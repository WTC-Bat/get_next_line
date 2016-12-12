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
		if (buff[cnt] == '\0')
		{
			return (0);
		}
		cnt++;
	}
	buff[cnt] = '\0';
	return (42);
}

static char	*get_text(const int fd)
{
	char	buff[BUFF_SIZE];
	char	*text;
	int		status;

	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL) //+1?
		return (NULL);
	status = 42;
	while (status != 0)
	{
		ft_memset(buff, '\0', BUFF_SIZE);
		status = fill_buff(fd, buff);
		text = ft_strcat(text, buff);
	}
	return (text);
}

static char	**get_lines(char *text)
{
	int		cnt;
	char	**lines;
	char	**outlines;

	if (text != NULL)
	{
		if ((outlines =
			(char **)malloc(sizeof(*outlines) * ft_splitcnt(text, '\n') + 1)) ==
			NULL)
		{
			return (NULL);
		}
		cnt = 0;
		lines = ft_strsplit(text, '\n');
		while (lines[cnt] != NULL)
		{
			outlines[cnt] = ft_strtrim(lines[cnt]);
			cnt++;
		}
		free_lines(lines);
		return (outlines);
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	static char	**lines;
	char		*text;

	if (fd < 0 || !line)
		return (-1);
	if (lines == NULL)
	{
		text = get_text(fd);
		lines = get_lines(text);
		ft_strdel(&text);
	}

	if (*lines == NULL)
	{
		return (0);
	}
	else
	{
		*line = ft_strdup(*lines);
		lines++;
		return (1);
	}
}





/*Working so far, just needs organizing*/

// #include "get_next_line.h"
//
// static int	fill_buff(const int fd, char *buff)
// {
// 	int		cnt;
// 	int		status;
//
// 	cnt = 0;
// 	status = 42;
// 	while (cnt < BUFF_SIZE - 1)
// 	{
// 		read(fd, &buff[cnt], 1);
// 		if (buff[cnt] == '\0')
// 		{
// 			return (0);
// 		}
// 		cnt++;
// 	}
// 	buff[cnt] = '\0';
// 	return (42);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	char		buff[BUFF_SIZE];
// 	char		*text;
// 	int			status;
// 	static int	pos;
// 	char		**lines;
//
// 	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL) //+1?
// 		return (-1);
// 	status = 42;
// 	if (!pos)
// 		pos = 0;
// 	while (status != 0)
// 	{
// 		ft_memset(buff, '\0', BUFF_SIZE);
// 		status = fill_buff(fd, buff);
// 		text = ft_strcat(text, buff);
// 	}
// 	lines = ft_strsplit(text, '\n');
// 	return (0);
// }
