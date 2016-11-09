/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 17:34:19 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/10 17:35:04 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(char *s, int c)
{
	size_t	len;

	len = (ft_strlen(s) + 1);

	while (len != 0)
	{
		if (*s == c)
			// return (*s);
			return (s);
		len--;
		s++;
	}
	return (0);



	// while (*s)
	// {
	// 	if (*s == c)
	// 		return (s);
	// 	s++;
	// }
	// return (0);
}
