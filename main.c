/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/05 11:52:15 by rbrune        #+#    #+#                 */
/*   Updated: 2022/07/01 12:14:15 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initiate_ol(t_ol *ol)
{
	ol->max_iteri = 300;
	ol->tmpx = 0;
	ol->tmpy = 0;
	ol->gridx = 0;
	ol->gridy = 0;
	ol->zoom = 1;
	ol->mousex = 0;
	ol->mousey = 0;
	ol->movex = 0;
	ol->movey = 0;
	ol->color[0] = 0x00EDF5FF;
	ol->color[1] = 0xFC0019FF;
	ol->color[2] = 0xFF01D7FF;
	ol->color[3] = 0x01FF4FFF;
	ol->color[4] = 0x5600CCFF;
	ol->color[5] = 0xFFEB00FF;
}

void	ft_err(int n)
{
	if (n == INVALID_ARG)
	{
		ft_putstr("Invalid number of parameters,\
 the available fractals are: Mandelbrot, bs (Burning_ship), \
Julia, Julia0, Julia1, Julia2.\n\
Or try to make your own with './fractol -0.9 0.2'");
	}
	else
		ft_putstr("Fractal not found, \
the available fractals are: Mandelbrot, bs (Burning_ship), \
Julia, Julia0, Julia1, Julia2.\n\
Or try to make your own with './fractol -0.9 0.2'");
	exit(1);
}

void	my_scrollhook(double xdelta, double ydelta, void *ol)
{
	double	temp_mousex;
	double	temp_mousey;

	mlx_get_mouse_pos(((t_ol *)ol)->mlx_p, &((t_ol *)ol)->mousex, \
	&((t_ol *)ol)->mousey);
	temp_mousex = ((t_ol *)ol)->mousex;
	temp_mousey = ((t_ol *)ol)->mousey;
	xdelta = 0;
	if (ydelta > 0)
	{
		((t_ol *)ol)->zoom *= 0.8;
		((t_ol *)ol)->movex += (temp_mousex / WIDTH - 0.5) * \
		((t_ol *)ol)->zoom;
		((t_ol *)ol)->movey += (temp_mousey / HEIGHT - 0.5) * \
		((t_ol *)ol)->zoom;
	}
	else if (ydelta < 0)
	{
		((t_ol *)ol)->movex -= \
		(temp_mousex / WIDTH - 0.5) *((t_ol *)ol)->zoom;
		((t_ol *)ol)->movey -= \
		(temp_mousey / HEIGHT - 0.5) *((t_ol *)ol)->zoom;
		((t_ol *)ol)->zoom /= 0.8;
	}
	generate_fractal(((t_ol *)ol));
}

void	my_keyhook(mlx_key_data_t keydata, void *ol)
{
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		mlx_close_window(((t_ol *)ol)->mlx_p);
	else if (keydata.key == MLX_KEY_UP && keydata.action == MLX_PRESS)
		((t_ol *)ol)->movey -= 0.1 * ((t_ol *)ol)->zoom;
	else if (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_PRESS)
		((t_ol *)ol)->movey += 0.1 * ((t_ol *)ol)->zoom;
	else if (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_PRESS)
		((t_ol *)ol)->movex -= 0.1 * ((t_ol *)ol)->zoom;
	else if (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_PRESS)
		((t_ol *)ol)->movex += 0.1 * ((t_ol *)ol)->zoom;
	if ((keydata.key >= MLX_KEY_RIGHT && keydata.key <= MLX_KEY_UP) \
	&& keydata.action == MLX_PRESS)
		generate_fractal(((t_ol *)ol));
	if ((keydata.key >= MLX_KEY_1 && keydata.key <= MLX_KEY_2) \
	&& keydata.action == MLX_PRESS)
		change_colors(((t_ol *)ol), keydata.key);
}

int	main(int ac, char *av[])
{
	t_ol				ol;

	ol.fractol = valid_fractol(ac, av, &ol);
	initiate_ol(&ol);
	ol.mlx_p = mlx_init(WIDTH, HEIGHT, "Fract'ol", true);
	if (!ol.mlx_p)
		exit(EXIT_FAILURE);
	ol.g_img_p = mlx_new_image(ol.mlx_p, WIDTH, HEIGHT);
	if (!ol.g_img_p)
		exit(EXIT_FAILURE);
	mlx_image_to_window(ol.mlx_p, ol.g_img_p, 0, 0);
	generate_fractal(&ol);
	mlx_scroll_hook(ol.mlx_p, &my_scrollhook, (void *)&ol);
	mlx_key_hook(ol.mlx_p, &my_keyhook, (void *)&ol);
	mlx_loop(ol.mlx_p);
	mlx_terminate(ol.mlx_p);
	return (EXIT_SUCCESS);
}
