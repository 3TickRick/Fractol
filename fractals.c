/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractals.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/12 15:23:14 by rbrune        #+#    #+#                 */
/*   Updated: 2022/07/01 12:13:32 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_burning_ship(t_ol *ol)
{
	while (ol->py < HEIGHT)
	{
		ol->px = 0;
		while (ol->px < WIDTH)
		{
			ol->iteri = 0;
			ol->gridx = (ol->px * ol->zoom * 4 / WIDTH) - \
			(2 * ol->zoom - ol->movex);
			ol->gridy = ol->py * ol->zoom * 4 / HEIGHT - \
			(2 * ol->zoom - ol->movey);
			while ((ol->gridx * ol->gridx + ol->gridy * ol->gridy) <= 4 \
			&& ol->iteri < ol->max_iteri)
			{
				ol->tmpx = ol->gridx * ol->gridx - ol->gridy * ol->gridy \
				+ ol->px * ol->zoom * 4 / WIDTH - (2 * ol->zoom - ol->movex);
				ol->tmpy = fabs(2 * ol->gridx * ol->gridy) + ol->py * \
				ol->zoom * 4 / HEIGHT - (2 * ol->zoom - ol->movey);
				ol->gridx = ol->tmpx;
				ol->gridy = ol->tmpy;
				ol->iteri += 1;
			}
			ft_color_screen(ol, 6, MANDELBROT);
		}
		ol->py++;
	}
}

void	ft_mandelbrot(t_ol *ol)
{
	while (ol->py < HEIGHT)
	{
		ol->px = 0;
		while (ol->px < WIDTH)
		{
			ol->iteri = 0;
			ol->gridx = (ol->px * ol->zoom * 4 / WIDTH) - \
			(2 * ol->zoom - ol->movex);
			ol->gridy = ol->py * ol->zoom * 4 / HEIGHT - \
			(2 * ol->zoom - ol->movey);
			while ((ol->gridx * ol->gridx + ol->gridy * ol->gridy) <= 4 \
			&& ol->iteri < ol->max_iteri)
			{
				ol->tmpx = ol->gridx * ol->gridx - ol->gridy * ol->gridy \
				+ ol->px * ol->zoom * 4 / WIDTH - (2 * ol->zoom - ol->movex);
				ol->tmpy = 2 * ol->gridx * ol->gridy + ol->py * \
				ol->zoom * 4 / HEIGHT - (2 * ol->zoom - ol->movey);
				ol->gridx = ol->tmpx;
				ol->gridy = ol->tmpy;
				ol->iteri += 1;
			}
			ft_color_screen(ol, 6, MANDELBROT);
		}
		ol->py++;
	}
}

void	ft_julia(t_ol *ol, double julia_typex, double julia_typey)
{
	while (ol->py < HEIGHT)
	{
		ol->px = 0;
		while (ol->px < WIDTH)
		{
			ol->iteri = 0;
			ol->gridx = (ol->px * ol->zoom * 4 / WIDTH) - \
			(2 * ol->zoom - ol->movex);
			ol->gridy = ol->py * ol->zoom * 4 / HEIGHT - \
			(2 * ol->zoom - ol->movey);
			while ((ol->gridx * ol->gridx + ol->gridy * ol->gridy) <= 4 \
			&& ol->iteri < ol->max_iteri)
			{
				ol->tmpx = ol->gridx * ol->gridx - ol->gridy * ol->gridy + \
				julia_typex;
				ol->tmpy = 2 * ol->gridx * ol->gridy + julia_typey;
				ol->gridx = ol->tmpx;
				ol->gridy = ol->tmpy;
				ol->iteri += 1;
			}
			ft_color_screen(ol, 3, julia_typey);
		}
		ol->py++;
	}
}

void	generate_fractal(t_ol *ol)
{
	ol->px = 0;
	ol->py = 0;
	if (ol->fractol == MANDELBROT)
	{
		ol->max_iteri = 75;
		ft_mandelbrot(ol);
	}
	if (ol->fractol == JULIA)
		ft_julia(ol, -0.4, -0.59);
	if (ol->fractol == JULIA0)
		ft_julia(ol, 0, 0);
	if (ol->fractol == JULIA1)
	{
		ol->color[0] = 0xF89880FF;
		ol->color[1] = 0xFFFF00FF;
		ft_julia(ol, 0, 0.8);
	}
	if (ol->fractol == JULIA2)
		ft_julia(ol, 0.34, -0.05);
	if (ol->fractol == BURNING_SHIP)
		ft_burning_ship(ol);
	if (ol->fractol == CUSTOM)
		ft_julia(ol, ol->inputx, ol->inputy);
}
