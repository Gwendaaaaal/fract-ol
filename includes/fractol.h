/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:17:31 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/11 15:47:47 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

// fract-ol settings
# define WIDTH 1600
# define HEIGHT 900
# define MAX_ITER 50

// keycodes
# define ARROW_UP 65362
# define ARROW_DOWN 65364
# define ARROW_RIGHT 65363
# define ARROW_LEFT 65361
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define SCROLL_UP 4
# define SCROLL_DOWN 5

// includes
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		x;
	int		y;
	int		color;
	double	zoom;
	double	offset_x;
	double	offset_y;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	char	*query;
}	t_data;

// draw.c
void	draw_mandelbrot(t_data *data);
int		draw_fractal(t_data *data);

// event_handlers.c
int		handle_key_event(int keysym, t_data *data);
int		handle_mouse_event(int mouse_sym, int x, int y, t_data *data);
int		handle_x(t_data *data);

//free.c
void	free_then_exit(t_data *data);

// init.c
void	init_data(t_data *data);
int		init_mlx(t_data *data);

// parse.c
int		parse(int argc, char **argv, t_data *data);

// utils.c
float	ft_atof(char *string);
double	ft_pow(double n1, double n2);
double	ft_abs(double n1);
void	img_pix_put(t_img *img, int x, int y, int color);
void	help(void);

#endif
