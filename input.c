/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/05/30 16:48:26 by rbrune        #+#    #+#                 */
/*   Updated: 2022/07/01 13:19:57 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	check_if_tof(const char *str)
{
	size_t	i;
	int		dot;

	if (!str)
		return (-2);
	i = 0;
	dot = 0;
	while (ft_isdigit(str[i]) || str[i] == '.' || \
		(str[i] == '-' && i == 0))
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (i == 1 && dot == 1)
		return (-2);
	if (i != ft_strlen(str) || dot > 1)
		return (-2);
	return (0);
}

double	ft_atof(const char *str)
{
	int		powa;
	int		index;
	double	value;
	double	sign;

	powa = 0;
	index = 0;
	value = 0;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		index++;
	}
	while (ft_isdigit(str[index]) || str[index] == '.')
	{
		if ((str[index - 1] == '.') || (powa > 0))
			powa += 1;
		if (str[index] != '.')
			value = value * 10 + (str[index] - 48);
		index++;
	}
	return ((value * sign) / pow(10, powa));
}

int	valid_fractol(int ac, char **av, t_ol *ol)
{
	if (ac < 2 || ac > 3)
		ft_err(INVALID_ARG);
	if (!ft_strcmp(ft_strlowcase(av[1]), "mandelbrot"))
		return (MANDELBROT);
	else if (!ft_strcmp(ft_strlowcase(av[1]), "julia"))
		return (JULIA);
	else if (!ft_strcmp(ft_strlowcase(av[1]), "julia0"))
		return (JULIA0);
	else if (!ft_strcmp(ft_strlowcase(av[1]), "julia1"))
		return (JULIA1);
	else if (!ft_strcmp(ft_strlowcase(av[1]), "julia2"))
		return (JULIA2);
	else if (!ft_strcmp(ft_strlowcase(av[1]), "bs"))
		return (BURNING_SHIP);
	else if (check_if_tof(av[1]) != -2 && check_if_tof(av[2]) != -2)
	{
		ol->inputx = ft_atof(av[1]);
		ol->inputy = ft_atof(av[2]);
		return (CUSTOM);
	}
	ft_err(WRONG_FRAC);
	exit(1);
}
