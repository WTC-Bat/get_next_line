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

// static int	fill_buff(const int fd, char *buff)
// {
// 	int		status;
// 	// int		rb;
// 	int		nidx;
//
// 	status = 42;
// 	read(fd, buff, BUFF_SIZE);
// 	cnt++;
// }

// static void	free_lines(char **lines)
// {
// 	int		cnt;
//
// 	cnt = 0;
// 	while (lines[cnt] != NULL)
// 	{
// 		ft_strdel(&lines[cnt]);
// 		cnt++;
// 	}
// }
//
// static char	**get_lines(char *text)
// {
// 	int		cnt;
// 	char	**lines;
// 	char	**outlines;
//
// 	if (text != NULL)
// 	{
// 		if ((outlines =
// 			(char **)malloc(sizeof(*outlines) * ft_splitcnt(text, '\n') + 1)) ==
// 			NULL)
// 		{
// 			return (NULL);
// 		}
// 		cnt = 0;
// 		lines = ft_strsplit(text, '\n');
// 		while (lines[cnt] != NULL)
// 		{
// 			outlines[cnt] = ft_strtrim(lines[cnt]);
// 			cnt++;
// 		}
// 		// free_lines(lines);
// 		// free(lines);
// 		return (outlines);
// 	}
// 	return (NULL);
// }

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
		// free_lines(lines);
		// free(lines);
		return (outlines);
	}
	return (NULL);
}

int			get_next_line(const int fd, char **line)
{
	char	buff[BUFF_SIZE];
	char	*text;

	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
		return (-1);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		buff[BUFF_SIZE - 1] = '\0';
		text = ft_strcat(text, buff);
	}

	return (0);
}

/*ALSO*/

// #include "get_next_line.h"

// static int	fill_buff(const int fd, char *buff)
// {
// 	int		status;
// 	// int		rb;
// 	int		nidx;
//
// 	status = 42;
// 	read(fd, buff, BUFF_SIZE);
// 	cnt++;
// }

// static void	free_lines(char **lines)
// {
// 	int		cnt;
//
// 	cnt = 0;
// 	while (lines[cnt] != NULL)
// 	{
// 		ft_strdel(&lines[cnt]);
// 		cnt++;
// 	}
// }
//
// static char	**get_lines(char *text)
// {
// 	int		cnt;
// 	char	**lines;
// 	char	**outlines;
//
// 	if (text != NULL)
// 	{
// 		if ((outlines =
// 			(char **)malloc(sizeof(*outlines) * ft_splitcnt(text, '\n') + 1)) ==
// 			NULL)
// 		{
// 			return (NULL);
// 		}
// 		cnt = 0;
// 		lines = ft_strsplit(text, '\n');
// 		while (lines[cnt] != NULL)
// 		{
// 			outlines[cnt] = ft_strtrim(lines[cnt]);
// 			cnt++;
// 		}
// 		// free_lines(lines);
// 		// free(lines);
// 		return (outlines);
// 	}
// 	return (NULL);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	char		buff[BUFF_SIZE];
// 	char		*text;
// 	char		**lines;
// 	int			nidx;
//
// 	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)) == NULL)
// 		return (-1);
// 	ft_memset(buff, '\0', BUFF_SIZE);
// 	while (read(fd, buff, BUFF_SIZE - 1) > 0)		//-1?
// 	{
// 		text = ft_strcat(text, buff);
// 		ft_memset(buff, '\0', BUFF_SIZE);
// 	}
//
// 	// lines = (char **)malloc(sizeof(*lines) * ft_splitcnt(text, '\n') + 1);
// 	// if (lines == NULL)
// 	// 	return (-1);
// 	// lines = ft_strsplit(text, '\n');
//
// 	lines = get_lines(text);
// 	if (lines == NULL)
// 	{
// 		return (-1);
// 	}
//
// 	return (0);
// }




/*ERRORING*/

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
// 		if (buff[cnt] == '\n')
// 		{
// 			buff[cnt] = '\0';
// 			return (1);
// 		}
// 		if (buff[cnt] == '\0')
// 			return (0);
// 		cnt++;
// 	}
// 	buff[cnt] = '\0';
// 	return (42);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	char		*l;
// 	char		buff[BUFF_SIZE];
// 	int			status;
//
// 	if (fd < 0 || *line == NULL || BUFF_SIZE < 1)
// 		return (-1);
// 	if ((l = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL)
// 		return (-1);
// 	status = 42;
// 	while (status == 42)
// 	{
// 		status = fill_buff(fd, &buff[0]);
// 		l = ft_strcat(l, buff);
// 	}
// 	*line = ft_strdup(l);
// 	ft_strdel(&l);
// 	return (status);
// }
