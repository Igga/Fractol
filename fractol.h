/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmanfrey <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 03:02:32 by bmanfrey          #+#    #+#             */
/*   Updated: 2019/10/23 03:03:31 by bmanfrey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <pthread.h>
# define WINDOW_W 500
# define WINDOW_H 500
# define THREADS 500
# define TYPE_MANDELBROT 1
# define TYPE_JULIA 2
# define TYPE_BURNINGSHIP 3
# define TYPE_CELTIC_MANDELBROT 4
# define TYPE_MANDELBAR 5
# define TYPE_CELTIC_MANDELBAR 6
# define TYPE_PERPENDICULAR_MANDELBROT 7
# define TYPE_PERPENDICULAR_BURNINGSHIP 8

typedef struct	s_util
{
	int			bpp;
	int			sl;
	int			endian;
}				t_util;

typedef struct	s_complex
{
	float		x;
	float		y;
}				t_complex;

typedef struct	s_fractal
{
	short		init;
	short		type;
	short		iterations;
	short		start_y;
	int			color;
	t_complex	complex;
	float		zoom;
	float		offset_x;
	float		offset_y;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	void		*img_ptr;
}				t_fractal;

void			burningship(t_fractal *fractal);
void			mandelbrot(t_fractal *fractal);
void			julia(t_fractal *fractal);
void			other_fractal(t_fractal *fractal);
void			fractal_startdraw(t_fractal *fractal);
void			fractal_init(t_fractal *fractal);
int				mouse_movehook(int x, int y, t_fractal *fractal);
int				mouse_hook(int button, int x, int y, t_fractal *fractal);
int				key_hook(int key, t_fractal *fractal);
int				killer(char *str);
int				killer_usage(void);
t_complex		complex_new(float x, float y);
t_complex		complex_plus(t_complex a, t_complex b);
t_complex		complex_sqr(t_complex a);
float			complex_abs(t_complex a);

#endif
