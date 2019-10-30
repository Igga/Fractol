/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:29:23 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:12:06 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	int	i;
	int	j;

	i = 0;
	if (!*str2)
		return ((char *)str1);
	while (str1[i] && len)
	{
		if (str1[i] == str2[0])
		{
			j = 1;
			while (str2[j] && str1[i + j] == str2[j] && (len - j))
				j++;
			if (!str2[j])
				return ((char *)str1 + i);
		}
		i++;
		len--;
	}
	return (NULL);
}
