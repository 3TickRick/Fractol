/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:26 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:27 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dst, const void *src, int n)
{
	int			index;
	char		*tmpdst;
	const char	*tmpsrc;

	tmpdst = dst;
	tmpsrc = src;
	index = 0;
	if (src == 0 && dst == 0)
		return (0);
	while (index < n)
	{
		tmpdst[index] = tmpsrc[index];
		index++;
	}
	return (dst);
}
