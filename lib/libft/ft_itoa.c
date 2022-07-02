/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:42 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:58 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int n)
{
	int	count;

	count = 0;
	if (n <= 0)
		count++;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*str;
	long	nb;

	nb = n;
	count = ft_count(n);
	str = malloc(count + 1);
	if (!str)
		return (NULL);
	if (nb < 0)
	{
		str[0] = (char) '-';
		nb = nb * -1;
	}
	else if (nb == 0)
		str[0] = '0';
	str[count] = (char) '\0';
	count--;
	while (count >= 0 && nb > 0)
	{
		str[count--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (str);
}
