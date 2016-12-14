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

static int	get_len(char *text, int *status, size_t pos)
{
	size_t	idx;
	size_t	len;

	idx = pos;
	len = 0;
	while (text[idx] != '\n' && text[idx] != '\0')
	{
		idx++;
		len++;
	}
	if (text[idx] == '\n')
		*status = 1;
	else if (text[idx] == '\0')
		*status = 0;
	return (len);
}

static char	*read_line(char *text, int *status, size_t *pos)
{
	size_t			idx;
	size_t			len;
	char			*line;
	unsigned int	upos;

	upos = (unsigned int)(*pos);
	len = get_len(text, status, *pos);
	line = ft_strsub(text, upos, len);
	*pos += (len + 1);
	return (line);
}

/*Successfully aquires all text from fd*/
int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	char		*text;
	int			status;
	static int	pos;
	char		**lines;

	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL)	//+1?
		return (-1);
	status = 42;
	pos = 0;
	ft_memset(buff, '\0', BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		text = ft_strcat(text, buff);
		ft_memset(buff, '\0', BUFF_SIZE);
	}
	if ((lines = ft_strsplit(text, '\n')) == NULL)
		return (-1);
	if (lines[pos] == NULL)
		return (0);
	else
	{
		*line = lines[pos++];
		return (1);
	}
}
