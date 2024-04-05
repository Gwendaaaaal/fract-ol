/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gholloco <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:17:31 by gholloco          #+#    #+#             */
/*   Updated: 2024/04/05 17:36:50 by gholloco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1600
# define HEIGHT 900
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include "Libft/libft.h"
# include <X11/keysym.h>
# include <math.h>
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
	char	*query;
}	t_data;

//free.c
void	free_then_exit(t_data *data);

// mlx_handlers.c
int	handle_no_event(void *data);
int	handle_key_event(int keysym, t_data *data);
int	handle_X(t_data *data);

// mlx.c
int	start_mlx(t_data *data);

// utils.c
void	img_pix_put(t_img *img, int x, int y, int color);

#endif
