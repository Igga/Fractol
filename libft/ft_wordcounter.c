/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 23:28:13 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/24 13:29:42 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wordcounter(char *str, char split)
{
	int words;
	int isword;

	words = 0;
	isword = 0;
	while (*str)
	{
		if (*str != split)
			isword = 1;
		else
		{
			if (isword)
				words++;
			isword = 0;
		}
		str++;
	}
	return (isword ? words + 1 : words);
}
