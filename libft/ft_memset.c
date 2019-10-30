/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:02:03 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:28:55 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *memptr, int val, size_t len)
{
	char *c;

	c = (char *)memptr;
	while (len)
	{
		*c = (char)val;
		c++;
		len--;
	}
	return (memptr);
}
