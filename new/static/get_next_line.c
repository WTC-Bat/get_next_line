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
// static void	fill_buff(const int fd, char *buff)
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
	// return (status);
	return (42);
}

// static char	*get_text(const int fd)
// {
//
// }

int			get_next_line(const int fd, char **line)
{
	char		buff[BUFF_SIZE];
	char		*text;
	int			status;
	static int	pos;
	char		**lines;
	char		*rtext;

	if ((text = (char *)malloc(sizeof(char) * BUFF_SIZE)) == NULL) //+1?
		return (-1);
	status = 42;
	if (!pos)
		pos = 0;
	while (status != 0)
	{
		ft_memset(buff, '\0', BUFF_SIZE);
		status = fill_buff(fd, buff);
		text = ft_strcat(text, buff);
	}
	// rtext = ft_strtrim(text);
	// ft_putendl(rtext);
	// ft_strdel(&text);
	// ft_putendl(text);

	lines = ft_strsplit(text, '\n');

	// int i = 0;
	// while (lines[i] != NULL)
	// {
	// 	ft_putendl(lines[i]);
	// 	ft_putchar('\n');
	// 	i++;
	// }
	return (0);
}



/*BACKUP1*/

// #include "get_next_line.h"
//
// static int	fill_buff(const int fd, char *buff)
// // static void	fill_buff(const int fd, char *buff)
// {
// 	int		cnt;
// 	int		rb;
//
// 	cnt = 0;
// 	// while (cnt < (BUFF_SIZE - 1))
// 	while (cnt < BUFF_SIZE)
// 	{
// 		rb = read(fd, &buff[cnt], 1);
// 		// if (buff[cnt] == '\n' || buff[cnt] == '\0')
// 		// 	break;
// 		if (buff[cnt] == '\n')	// if (ft_indexof(buff, '\n') == 1)
// 			return (1);
// 		// else if (buff[cnt] == '\0')	//May not always get checked
// 		else if (buff[cnt] == '\0' || rb == 0)	//May not always get checked
// 			return (0);
// 		cnt++;
// 	}
// 	buff[cnt] = '\0';
// 	return (42);
// }
//
// // static char	*get_text(const int fd)
// // {
// //
// // }
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
// 	// lines = ft_strsplit(text, '\n');
// 	// int i = 0;
// 	// while (lines[i] != NULL)
// 	// {
// 	// 	ft_putendl(lines[i]);
// 	// 	ft_putchar('\n');
// 	// 	i++;
// 	// }
// 	return (0);
// }