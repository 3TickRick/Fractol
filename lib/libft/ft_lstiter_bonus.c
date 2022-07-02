/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstiter_bonus.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:34 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:35 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmpnext;

	while (lst)
	{
		tmpnext = lst->next;
		f(lst->content);
		lst = tmpnext;
	}
}
