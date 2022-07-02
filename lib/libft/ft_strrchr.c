/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:13:51 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:13:52 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		index;

	index = 0;
	while (s[index])
		index++;
	while (index > 0)
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index--;
	}
	if (s[index] == (char)c)
		return ((char *)&s[index]);
	return (NULL);
}
