/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:15:12 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:15:13 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int	value;
	int	neg;

	neg = 1;
	value = 0;
	while (*str == ' ' || *str == '\t' || *str == '\v' || \
			*str == '\f' || *str == '\r' || *str == '\n')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		value *= 10;
		value += (*str - '0');
		str++;
	}
	return (value * neg);
}
