/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:13:33 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/29 12:02:09 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_stpcpy(char *dst, const char *src);

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	str = ft_calloc(1, ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	if (str)
		ft_stpcpy(ft_stpcpy(str, s1), s2);
	return (str);
}

static char	*ft_stpcpy(char *dst, const char *src)
{
	while (*src)
		*dst++ = *src++;
	*dst = '\0';
	return (dst);
}
