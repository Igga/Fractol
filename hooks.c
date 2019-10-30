/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:03:48 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/25 06:27:09 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_movehook(int x, int y, t_fractal *fractal)
{
	float	fx;
	float	fy;

	fx = x;
	fy = y;
	if (fractal->type == TYPE_JULIA)
	{
		fractal->complex.x = fx * 2 / WINDOW_W - 1;
		fractal->complex.y = fy * 2 / WINDOW_H - 1;
		fractal_startdraw(fractal);
	}
	return (1);
}

int		mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	float fx;
	float fy;

	fx = x;
	fy = y;
	if (button == 4)
	{
		fractal->offset_x +=
(0.008 * (fx / fractal->zoom - fx / (fractal->zoom * 1.2)));
		fractal->offset_y +=
(0.008 * (fy / fractal->zoom - fy / (fractal->zoom * 1.2)));
		fractal->zoom *= 1.2;
	}
	if (button == 5 && fractal->zoom > 0.5)
	{
		fractal->zoom /= 1.2;
		fractal->offset_x -=
(0.008 * (fx / fractal->zoom - fx / (fractal->zoom * 1.2)));
		fractal->offset_y -=
(0.008 * (fy / fractal->zoom - fy / (fractal->zoom * 1.2)));
	}
	fractal_startdraw(fractal);
	return (1);
}

void	key_hook1(int key, t_fractal *fractal)
{
	if (key == 24)
		fractal->iterations += 2;
	if (key == 27 && fractal->iterations > 2)
		fractal->iterations -= 2;
	if (key == 126)
		fractal->offset_y += (0.1 / fractal->zoom);
	if (key == 125)
		fractal->offset_y -= (0.1 / fractal->zoom);
	if (key == 124)
		fractal->offset_x -= (0.1 / fractal->zoom);
	if (key == 123)
		fractal->offset_x += (0.1 / fractal->zoom);
	if (key == 12 && fractal->color > 0x0)
		fractal->color -= 0x010101;
	if (key == 13)
	{
		fractal->color += 0x101010;
		if (fractal->color > 0xffffff)
			fractal->color += 0x000001;
	}
}

int		key_hook(int key, t_fractal *fractal)
{
	key_hook1(key, fractal);
	if (key == 18)
		fractal->color = 0xffffff;
	if (key == 19)
		fractal->color = 0x000205;
	if (key == 20)
		fractal->color = 0x112233;
	if (key == 53)
	{
		mlx_destroy_image(fractal->mlx_ptr, fractal->img);
		mlx_destroy_window(fractal->mlx_ptr, fractal->win_ptr);
		free(fractal);
		exit(0);
	}
	fractal_startdraw(fractal);
	return (1);
}
