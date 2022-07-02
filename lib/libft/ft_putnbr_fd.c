/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:10 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/20 15:08:39 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	modulo_hell(int nb, int fd)
{
	if (nb > 0)
	{
		modulo_hell (nb / 10, fd);
		ft_putchar_fd(nb % 10 + '0', fd);
	}
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		modulo_hell((nb / 10) * -1, fd);
		ft_putchar_fd(nb % 10 * -1 + '0', fd);
	}
}

void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == 0)
	{
		write(fd, "0", 1);
	}
	else
	{
		modulo_hell(nb, fd);
	}
}
