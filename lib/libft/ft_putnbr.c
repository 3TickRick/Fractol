/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:12 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:13 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	modulo_hell(int nb)
{
	if (nb > 0)
	{
		modulo_hell (nb / 10);
		ft_putchar (nb % 10 + '0');
	}
	if (nb < 0)
	{
		ft_putchar('-');
		modulo_hell((nb / 10) * -1);
		ft_putchar(nb % 10 * -1 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
	{
		ft_putchar('0');
	}
	else
	{
		modulo_hell(nb);
	}
}
