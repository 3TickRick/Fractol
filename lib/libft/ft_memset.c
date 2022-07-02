/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:24 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:25 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t n)
{
	size_t			index;
	unsigned char	*mem;

	mem = b;
	index = 0;
	while (index < n)
	{
		mem[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
