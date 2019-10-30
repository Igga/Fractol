/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 21:57:57 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:10:21 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str1, const char *str2)
{
	int		i;
	int		j;

	i = 0;
	if (!*str2)
		return ((char *)str1);
	while (str1[i])
	{
		if (str1[i] == str2[0])
		{
			j = 1;
			while (str2[j] && str1[i + j] == str2[j])
				j++;
			if (!str2[j])
				return ((char *)str1 + i);
		}
		i++;
	}
	return (NULL);
}
