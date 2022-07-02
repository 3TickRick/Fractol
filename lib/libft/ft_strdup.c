/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:13:30 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:13:31 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s1cpy;
	size_t	i;

	i = 0;
	s1cpy = malloc(ft_strlen((char *)s1) + 1);
	if (!s1cpy)
		return (0);
	while (i < ft_strlen((char *)s1))
	{
		s1cpy[i] = s1[i];
		i++;
	}
	s1cpy[i] = '\0';
	return (s1cpy);
}
