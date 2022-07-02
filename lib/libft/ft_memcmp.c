/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:27 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:28 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int					index;
	const unsigned char	*c1;
	const unsigned char	*c2;

	c2 = s2;
	c1 = s1;
	index = 0;
	while (index < (int)n)
	{
		if (c1[index] != c2[index])
			return (c1[index] - c2[index]);
		index++;
	}
	return (0);
}
