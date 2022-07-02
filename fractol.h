/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/03/16 11:45:54 by rbrune        #+#    #+#                 */
/*   Updated: 2022/06/01 14:55:45 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* MLX */
# include "./lib/MLX42/include/MLX42/MLX42.h"

/* own library */
# include "./lib/libft/libft.h"

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

/* MLX info */
# define WIDTH 1000
# define HEIGHT 1000

# define INVALID_ARG 1
# define WRONG_FRAC 2

/* Available fractals */
# define JULIA				0
# define JULIA0				1
# define JULIA1				2
# define JULIA2				3
# define MANDELBROT			4
# define BURNING_SHIP		5
# define CUSTOM				6

typedef struct s_fractol
{
	int					fractol;
	double				px;
	double				py;
	double				gridx;
	double				gridy;
	double				tmpx;
	double				tmpy;
	double				type_ftol;
	double				zoom;
	double				movex;
	double				movey;
	double				inputx;
	double				inputy;
	int					mousex;
	int					mousey;
	int					iteri;
	int					max_iteri;
	unsigned int		color[6];
	mlx_image_t			*g_img_p;
	mlx_t				*mlx_p;
}t_ol;

void	generate_fractal(t_ol *ol);
void	change_colors(t_ol *ol, int key);
int		valid_fractol(int ac, char **av, t_ol *ol);
void	ft_err(int n);
void	ft_color_screen(t_ol *ol, int n, double type);
#endif