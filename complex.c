/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:57:47 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/23 02:58:42 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex	complex_new(float x, float y)
{
	t_complex ans;

	ans.x = x;
	ans.y = y;
	return (ans);
}

t_complex	complex_plus(t_complex a, t_complex b)
{
	t_complex	ans;

	ans.x = a.x + b.x;
	ans.y = a.y + b.y;
	return (ans);
}

t_complex	complex_sqr(t_complex a)
{
	t_complex	ans;

	ans.x = pow(a.x, 2) - pow(a.y, 2);
	ans.y = 2 * a.x * a.y;
	return (ans);
}

float		complex_abs(t_complex a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2)));
}
