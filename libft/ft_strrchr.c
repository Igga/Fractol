/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:53:59 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:12:56 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *str, int s)
{
	int i;

	if (s == '\0')
		return ((char *)(str + ft_strlen(str)));
	i = ft_strlen(str);
	while (i && str[i] != s)
		i--;
	if (str[i] == s)
		return ((char *)(str + i));
	return (NULL);
}
