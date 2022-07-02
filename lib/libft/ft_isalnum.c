/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isalnum.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:15:07 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:15:08 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else if (c > 90 && c < 97)
		return (0);
	else if (c < 65)
		return (0);
	else if (c > 122)
		return (0);
	else
		return (1);
}
