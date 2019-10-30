/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:07:49 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:32:54 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *mem;

	mem = (char*)malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return ((void *)mem);
}
