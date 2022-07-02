/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/23 11:44:47 by rbrune        #+#    #+#                 */
/*   Updated: 2022/05/30 14:25:27 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_color_scheme(t_ol *ol, int n)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (n < 0)
			ol->color[i] -= (n * 40000);
		else
			ol->color[i] += (n * 40000);
		generate_fractal(ol);
		i++;
	}
}

void	change_colors(t_ol *ol, int key)
{
	if (key == MLX_KEY_1)
		ft_color_scheme(ol, 2);
	else if (key == MLX_KEY_2)
		ft_color_scheme(ol, -2);
}

void	ft_color_screen(t_ol *ol, int n, double type)
{
	if (type == MANDELBROT)
	{
		if (ol->iteri == ol->max_iteri)
			mlx_put_pixel(ol->g_img_p, ol->px, ol->py, 0x00000000);
		else if (ol->iteri > 3)
			mlx_put_pixel(ol->g_img_p, ol->px, ol->py, \
			ol->color[ol->iteri % n]);
		else
			mlx_put_pixel(ol->g_img_p, ol->px, ol->py, 0xFFFFFFFF);
	}
	else if (type != 0)
	{
		if (ol->iteri > 18)
			mlx_put_pixel(ol->g_img_p, ol->px, ol->py, \
			ol->color[ol->iteri / 4 % n]);
		else
			mlx_put_pixel(ol->g_img_p, ol->px, ol->py, 0xADD8E6FF);
	}
	else
		mlx_put_pixel(ol->g_img_p, ol->px, ol->py, ol->color[ol->iteri % n]);
	ol->px++;
}
