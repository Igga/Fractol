/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:33:23 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/07 01:12:37 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	unsigned char	*str;
	unsigned long	num;
	int				neg;

	str = (unsigned char *)s;
	num = 0;
	neg = 0;
	while (*str == ' ' || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		if (num > 922337203685477580 || (num == 922337203685477580
			&& (*str - '0') > (neg ? 8 : 7)))
			return (neg ? 0 : -1);
		num = num * 10 + *str - '0';
		str++;
	}
	return (neg ? (int)-num : (int)num);
}
