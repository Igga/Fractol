/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:49:41 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:30:41 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *buffer, int ch, size_t n)
{
	size_t			i;
	unsigned char	*save;

	i = 0;
	save = (unsigned char *)buffer;
	while (i < n)
	{
		if (save[i] == (unsigned char)ch)
			return (save + i);
		i++;
	}
	return (NULL);
}
