/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:22:10 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/16 16:44:16 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned int	i;
	char			*ans;

	if (!s || !f)
		return (NULL);
	ans = ft_strnew(ft_strlen(s));
	if (!ans)
		return (NULL);
	i = 0;
	while (s[i])
	{
		ans[i] = f(s[i]);
		i++;
	}
	return (ans);
}
