/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 02:19:03 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:26:09 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	unsigned int i;

	if (n < 0)
	{
		ft_putchar('-');
		i = (unsigned int)-n;
	}
	else
		i = (unsigned int)n;
	if (i > 9)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}
