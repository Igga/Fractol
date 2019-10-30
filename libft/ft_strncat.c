/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:23:00 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:18:42 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t len;

	len = ft_strlen(src);
	if (len > n)
		len = n;
	*(dest + ft_strlen(dest) + len) = '\0';
	ft_memcpy(dest + ft_strlen(dest), src, len);
	return (dest);
}
