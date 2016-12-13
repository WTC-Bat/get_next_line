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
	ft_putendl("GOT LEN");
	line = ft_strsub(text, upos, len);
	ft_putendl("SUBBED");
	*pos += (len + 1);
	return (line);
}

/*Successfully aquires all text from fd*/
int			get_next_line(const int fd, char **line)
{
	char			buff[BUFF_SIZE];
	char			*text;
	int				status;
	static size_t	pos;
	char			**lines;

	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL)	//+1?
		return (-1);
	status = 42;
	ft_memset(buff, '\0', BUFF_SIZE);
	while (read(fd, buff, BUFF_SIZE - 1) > 0)
	{
		text = ft_strcat(text, buff);
		ft_memset(buff, '\0', BUFF_SIZE);
	}
	ft_putendl("LINES");
	//
	if ((lines = (char **)malloc(sizeof(*lines) * ft_splitcnt(text, '\n') + 1)) == NULL)
		return (-1);
	lines = ft_strsplit(text, '\n');
	ft_strdel(&text);
	free(lines);
	//
	// ft_putendl("READING LINE");
	// *line = read_line(text, &status, &pos);
	// ft_strdel(&text);
	// ft_putendl("LINE: ");
	// ft_putendl(*line);

	return (0);
	// return (status);
}
