/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvanwyk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:08:17 by mvanwyk           #+#    #+#             */
/*   Updated: 2016/05/15 15:08:19 by mvanwyk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int		cnt;

	cnt = 0;
	if (s != NULL)
	{
		while (s[cnt] != '\0')
		{
			s[cnt] = '\0';
			cnt++;
		}
	}
}