/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 02:29:03 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/23 02:39:58 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_startdraw(t_fractal *fractal)
{
	if (fractal->type == TYPE_MANDELBROT)
		return (mandelbrot(fractal));
	if (fractal->type == TYPE_JULIA)
		return (julia(fractal));
	if (fractal->type == TYPE_BURNINGSHIP)
		return (burningship(fractal));
	other_fractal(fractal);
}

int		fractal_typeset(char *str, t_fractal *fractal)
{
	if (!ft_strcmp(str, "mandelbrot"))
		return (fractal->type = TYPE_MANDELBROT);
	if (!ft_strcmp(str, "julia"))
		return (fractal->type = TYPE_JULIA);
	if (!ft_strcmp(str, "burningship"))
		return (fractal->type = TYPE_BURNINGSHIP);
	if (!ft_strcmp(str, "celtic_mandelbrot"))
		return (fractal->type = TYPE_CELTIC_MANDELBROT);
	if (!ft_strcmp(str, "mandelbar"))
		return (fractal->type = TYPE_MANDELBAR);
	if (!ft_strcmp(str, "celtic_mandelbar"))
		return (fractal->type = TYPE_CELTIC_MANDELBAR);
	if (!ft_strcmp(str, "p_mandelbrot"))
		return (fractal->type = TYPE_PERPENDICULAR_MANDELBROT);
	if (!ft_strcmp(str, "p_burningship"))
		return (fractal->type = TYPE_PERPENDICULAR_BURNINGSHIP);
	return (0);
}

int		main(int argc, char *argv[])
{
	t_fractal	*fractal;
	t_util		util;

	if (!(fractal = (t_fractal *)malloc(sizeof(t_fractal))))
		return (killer("error"));
	if (argc != 2 || !fractal_typeset(argv[1], fractal))
		return (killer_usage());
	if (!(fractal->mlx_ptr = mlx_init()))
		return (killer("error"));
	fractal->win_ptr = mlx_new_window(fractal->mlx_ptr,
WINDOW_W, WINDOW_H, "Fractol");
	if (!fractal->win_ptr)
		return (killer("error"));
	fractal->init = 0;
	fractal->img = mlx_new_image(fractal->mlx_ptr, WINDOW_W, WINDOW_H);
	fractal->img_ptr = mlx_get_data_addr(fractal->img, &util.bpp,
&util.sl, &util.endian);
	mlx_mouse_hook(fractal->win_ptr, mouse_hook, (void *)fractal);
	mlx_key_hook(fractal->win_ptr, key_hook, (void *)fractal);
	mlx_hook(fractal->win_ptr, 4, 0, mouse_hook, (void *)fractal);
	mlx_hook(fractal->win_ptr, 6, 0, mouse_movehook, (void *)fractal);
	fractal_startdraw(fractal);
	mlx_loop(fractal->mlx_ptr);
	return (0);
}
