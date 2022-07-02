/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:15:11 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:15:12 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, int n)
{
	int		index;
	char	*mem;

	mem = b;
	index = 0;
	while (index < n)
	{
		mem[index] = '\0';
		index++;
	}
}
