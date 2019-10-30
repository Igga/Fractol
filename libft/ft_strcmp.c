/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 22:33:54 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:22:03 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *str1, const char *str2)
{
	int i;

	i = -1;
	while (str1[++i] && str1[i] == str2[i])
		;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
