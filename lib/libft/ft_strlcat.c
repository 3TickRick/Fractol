/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:13:37 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:16:28 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	init_dst;

	init_dst = ft_strlen(dst);
	i = 0;
	if (dstsize <= init_dst)
		return (ft_strlen((char *)src) + dstsize);
	while (init_dst + i < dstsize - 1 && src[i])
	{
		dst[init_dst + i] = src[i];
		i++;
	}
	dst[init_dst + i] = '\0';
	return (ft_strlen((char *)src) + init_dst);
}
