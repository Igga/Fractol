/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:39:43 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:09:51 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*ans;
	unsigned int	i;
	size_t			j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	while (j > i && (ft_isspace(s[j])))
		j--;
	ans = ft_strsub(s, i, j - i + 1);
	return (ans);
}
