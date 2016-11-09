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

#include "get_next_line.h"
#include <fcntl.h>

// int		get_next_line(const int fd, char **line)
// {
// 	char	chr;
// 	char	*ln;
// 	ssize_t	rb;
//
// 	while (chr != '\n')
// 	{
// 		rb = read(fd, &chr, 1);
// 		ln = ft_strjoin(ln, &chr);
// 		ft_putchar(chr);
// 	}
// 	ft_putendl(ln);
// 	return (42);
// }

static int	indexof(char *str, char ch)
{
	int		idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] == ch)
			return (idx);
		idx++;
	}
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*reads;


}
