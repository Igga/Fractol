/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:36:27 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:20:01 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ans;

	if (!s1 || !s2)
		return (NULL);
	ans = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!ans)
		return (NULL);
	ft_strcat(ans, s1);
	ft_strcat(ans, s2);
	return (ans);
}
