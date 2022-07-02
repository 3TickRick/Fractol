/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear_bonus.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:38 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:39 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmpnext;

	while (*lst && lst)
	{
		tmpnext = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = tmpnext;
	}
}
