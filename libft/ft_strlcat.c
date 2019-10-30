/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:37:50 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:19:09 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(dest);
	if (ft_strlen(dest) > size)
		return (size + ft_strlen(src));
	ft_strncat(dest, src, size - ft_strlen(dest) - 1);
	return (len + ft_strlen(src));
}
