/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 04:21:27 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/16 17:49:29 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_alphabet(void)
{
	char a;

	a = 'a';
	while (a != 'z' + 1)
		ft_putchar(a++);
}
