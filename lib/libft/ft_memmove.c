/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:25 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:26 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memmove(void *dst, void *src, int n)
{
	int		index;
	char	*tmpdst;
	char	*tmpsrc;

	tmpdst = dst;
	tmpsrc = src;
	index = 0;
	if (src == 0 && dst == 0)
		return (0);
	if (src < dst)
	{
		while (n > 0)
		{
			n--;
			tmpdst[n] = tmpsrc[n];
		}
	}
	while (index < n)
	{
		tmpdst[index] = tmpsrc[index];
		index++;
	}
	return (dst);
}
