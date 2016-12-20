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

static int	get_len(char *text, int *pos, int *status)
{
	int		len;
	int		cnt;

	len = 0;
	cnt = *pos;

	while (text[cnt] != '\0')
	{
		if (text[cnt] == '\n')
		{
			*status = 1;
			return (len);
		}
		len++;
		cnt++;
	}
	*status = 0;
	return (len);
}

static char	*read_line(char *text, int *pos, int *status)
{
	int		len;
	char	*ln;

	len = get_len(text, pos, status);
	ln = ft_strsub(text, *pos, len);
	*pos += len + 1;
	return (ln);
}

static char	*get_text(const int fd)
{
	char	buff[BUFF_SIZE + 1];
	char	*result;
	char	*tmp;

	ft_memset(buff, '\0', (BUFF_SIZE + 1));
	result = NULL;
	while (read(fd, buff, BUFF_SIZE) > 0)
	{
		if (result == NULL)
			result = ft_strdup(buff);
		else
		{
			tmp = ft_strdup(result);
			ft_strdel(&result);
			result = ft_strjoin(tmp, buff);
			ft_strdel(&tmp);
		}
		ft_memset(buff, '\0', (BUFF_SIZE + 1));
	}
	return (result);
}

int			get_next_line(const int fd, char **line)
{
	static int	pos = 0;	// = 0? instead of below?
	static char	*text;
	char		*ln;
	int			status;

	if (fd < 0 || line == NULL)
		return (-1);
	status = 42;
	if (!text)
		text = get_text(fd);
	ln = read_line(text, &pos, &status);
	if (ln == NULL)
		return (-1);
	*line = ln;
	return (status);
}





/*
**	Basic Tests:	7 Fail
**	Moulitest:		19 Fail
*/

// static int	get_len(char *text, int *pos, int *status)
// {
// 	int		len;
// 	int		cnt;
//
// 	len = 0;
// 	cnt = *pos;
// 	while (text[cnt] != '\n' && text[cnt] != '\0')
// 	{
// 		len++;
// 		cnt++;
// 	}
// 	if (text[cnt] == '\n')
// 		*status = 1;
// 	else
// 		*status = 0;
// 	return (len);
// }
//
// static char	*read_line(char *text, int *pos, int *status)
// {
// 	int		len;
// 	char	*ln;
//
// 	len = get_len(text, pos, status);
// 	// if (len == 0)
// 	if (len == 0 || *pos >= (int)ft_strlen(text) - 1)
// 		return (NULL);
// 	ln = ft_strsub(text, *pos, len);
// 	*pos += len + 1;
// 	return (ln);
// }
//
// static char	*get_text(const int fd)
// {
// 	char	buff[BUFF_SIZE + 1];
// 	char	*result;
// 	char	*tmp;
//
// 	ft_memset(buff, '\0', (BUFF_SIZE + 1));
// 	result = NULL;
// 	while (read(fd, buff, BUFF_SIZE) > 0)
// 	{
// 		if (result == NULL)
// 			result = ft_strdup(buff);
// 		else
// 		{
// 			tmp = ft_strdup(result);
// 			ft_strdel(&result);
// 			result = ft_strjoin(tmp, buff);
// 			ft_strdel(&tmp);
// 		}
// 		ft_memset(buff, '\0', (BUFF_SIZE + 1));
// 	}
// 	return (result);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	static int	pos = 0;	// = 0? instead of below?
// 	static char	*text;
// 	char		*ln;
// 	int			status;
//
// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	status = 42;
// 	if (!text)
// 		text = get_text(fd);
// 	ln = read_line(text, &pos, &status);
// 	if (ln == NULL)
// 		return (-1);
// 	*line = ln;
// 	return (status);
// }





/*
**	Basic Tests:	8 Fail
**	Moulitest:		20 Fail
*/

// static int	get_len(char *text, int *pos, int *status)
// {
// 	int		len;
// 	int		cnt;
//
// 	len = 0;
// 	cnt = *pos;
// 	while (text[cnt] != '\n' && text[cnt] != '\0')
// 	{
// 		len++;
// 		cnt++;
// 	}
// 	if (text[cnt] == '\n')
// 		*status = 1;
// 	else
// 		*status = 0;
// 	return (len);
// }
//
// static char	*read_line(char *text, int *pos, int *status)
// {
// 	int		len;
// 	char	*ln;
//
// 	len = get_len(text, pos, status);
// 	//if (len == 0)
// 	ln = ft_strsub(text, *pos, len);
// 	*pos += len + 1;
// 	return (ln);
// }
//
// static char	*get_text(const int fd)
// {
// 	char	buff[BUFF_SIZE + 1];
// 	char	*result;
// 	char	*tmp;
//
// 	ft_memset(buff, '\0', (BUFF_SIZE + 1));
// 	result = NULL;
// 	while (read(fd, buff, BUFF_SIZE) > 0)
// 	{
// 		if (result == NULL)
// 			result = ft_strdup(buff);
// 		else
// 		{
// 			tmp = ft_strdup(result);
// 			ft_strdel(&result);
// 			result = ft_strjoin(tmp, buff);
// 			ft_strdel(&tmp);
// 		}
// 		ft_memset(buff, '\0', (BUFF_SIZE + 1));
// 	}
// 	return (result);
// }
//
// int			get_next_line(const int fd, char **line)
// {
// 	static int	pos = 0;	// = 0? instead of below?
// 	static char	*text;
// 	char		*ln;
// 	int			status;
//
// 	if (fd < 0 || line == NULL)
// 		return (-1);
// 	status = 42;
// 	if (!text)
// 		text = get_text(fd);
// 	ln = read_line(text, &pos, &status);
// 	if (ln == NULL)
// 		return (-1);
// 	*line = ln;
// 	return (status);
// }
