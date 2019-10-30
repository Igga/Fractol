/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:39:28 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/23 03:40:08 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		killer_usage(void)
{
	ft_putstr("usage: ./fractol mandelbrot/julia/");
	ft_putstr("burningship/celtic_mandelbrot");
	ft_putstr("/mandelbar/celtic_mandelbar/");
	return (killer("p_mandelbrot/p_burningship"));
}

int		killer(char *str)
{
	ft_putendl(str);
	return (0);
}

void	fractal_init(t_fractal *fractal)
{
	fractal->iterations = 60;
	fractal->offset_x = 0;
	fractal->offset_y = 0;
	fractal->zoom = 1;
	fractal->color = 0x000205;
	fractal->init = 1;
}
