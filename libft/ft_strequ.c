/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 01:27:40 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/01/12 15:21:20 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strequ(char const *s1, char const *s2)
{
	unsigned int i;

	if (!s1 || !s2)
		return (0);
	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] == s2[i]);
}
