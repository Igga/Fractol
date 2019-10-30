/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 14:09:22 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/11 16:21:05 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_itoa(int n)
{
	int				s;
	int				len;
	char			*ans;
	unsigned int	num;

	len = n < 0 ? 2 : 1;
	s = n;
	while ((s = s / 10))
		len++;
	if (!(ans = ft_strnew(len)))
		return (NULL);
	num = n > 0 ? n : -n;
	while (len)
	{
		ans[len - 1] = num % 10 + '0';
		num = num / 10;
		len--;
	}
	if (n < 0)
		ans[0] = '-';
	return (ans);
}
