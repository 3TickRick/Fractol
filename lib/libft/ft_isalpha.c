/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalpha.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:15:06 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:15:07 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if (c > 90 && c < 97)
		return (0);
	else if (c < 65)
		return (0);
	else if (c > 122)
		return (0);
	else
		return (1);
}
