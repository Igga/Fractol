/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:31:39 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:10:44 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*ans;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = 0;
	ans = ft_strnew(len);
	if (!ans)
		return (NULL);
	while (len)
	{
		ans[i] = s[start];
		i++;
		start++;
		len--;
	}
	return (ans);
}
