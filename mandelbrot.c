/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:17:45 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/23 03:22:38 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mandelbrot_color(t_fractal *fractal, float y, float x)
{
	t_complex	c;
	t_complex	z;
	int			it;
	int			color;

	it = 0;
	z = complex_new(0, 0);
	c = complex_new((x * 4 / WINDOW_W / fractal->zoom) - 2 + fractal->offset_x,
(y * 4 / WINDOW_H / fractal->zoom) - 2 + fractal->offset_y);
	while (complex_abs(z) < 2 && it < fractal->iterations)
	{
		z = complex_plus(complex_sqr(z), c);
		it++;
	}
	if (it == fractal->iterations)
		color = 0x000000;
	else
		color = fractal->color * it;
	return (color);
}

void	*mandelbrot_draw(void *v_fractal)
{
	t_fractal	*fractal;
	int			y;
	int			max_y;
	int			x;
	int			color;

	fractal = (t_fractal *)v_fractal;
	y = fractal->start_y;
	max_y = y + WINDOW_H / THREADS;
	while (y < max_y && y < WINDOW_H)
	{
		x = 0;
		while (x < WINDOW_W)
		{
			color = mlx_get_color_value(fractal->mlx_ptr,
mandelbrot_color(fractal, y, x));
			ft_memcpy((void *)(fractal->img_ptr + 4 * WINDOW_W * y + 4 * x),
&color, sizeof(int));
			x++;
		}
		y++;
	}
	return (fractal);
}

void	mandelbrot_drawinfo(t_fractal *fractal)
{
	char	*count;
	char	*str;

	str = ft_strjoin("mandelbrot: ", "1/2/3 q/w  +/- wheel arrows");
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr,
10, WINDOW_H - 20, 0xffffff, str);
	free(str);
	count = ft_itoa(fractal->iterations);
	str = ft_strjoin("max iterations: ", count);
	mlx_string_put(fractal->mlx_ptr, fractal->win_ptr,
10, 10, 0xffffff, str);
	free(str);
	free(count);
}

void	mandelbrot(t_fractal *fractal)
{
	pthread_t	threads[THREADS];
	t_fractal	f[THREADS];
	int			i;

	if (!fractal->init)
		fractal_init(fractal);
	i = 0;
	ft_bzero(fractal->img_ptr, 4 * WINDOW_W * WINDOW_H);
	while (i < THREADS)
	{
		ft_memcpy((void *)&f[i], (void *)fractal, sizeof(t_fractal));
		f[i].start_y = WINDOW_H / THREADS * i;
		pthread_create(&threads[i], NULL, mandelbrot_draw, &f[i]);
		i++;
	}
	while (i--)
		pthread_join(threads[i], NULL);
	mlx_put_image_to_window(fractal->mlx_ptr,
fractal->win_ptr, fractal->img, 0, 0);
	mandelbrot_drawinfo(fractal);
}
