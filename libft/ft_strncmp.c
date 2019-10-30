/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:40:42 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:14:11 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *str1, const char *str2, size_t num)
{
	int	i;

	i = -1;
	if (!num)
		return (0);
	num--;
	while (str1[++i] && str1[i] == str2[i] && num)
		num--;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
