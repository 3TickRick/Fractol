/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:13:53 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:13:54 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	begin;
	size_t	end;

	begin = 0;
	while (s1[begin] && ft_char_in_set(s1[begin], set))
		begin++;
	end = ft_strlen((char *)s1);
	while (end > begin && ft_char_in_set(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - begin + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (begin < end)
		str[i++] = s1[begin++];
	str[i] = 0;
	return (str);
}
