/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 19:15:24 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:21:39 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		len;

	len = ft_strlen(src) + 1;
	copy = (char *)malloc(len);
	if (!copy)
		return (NULL);
	return (ft_memcpy(copy, src, len));
}
