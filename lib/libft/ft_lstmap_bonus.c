/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rbrune <rbrune@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/04/08 11:14:32 by rbrune        #+#    #+#                 */
/*   Updated: 2022/04/08 11:14:33 by rbrune        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*f_lst;

	tmp = NULL;
	f_lst = tmp;
	while (lst)
	{
		tmp = ft_lstnew(f(lst->content));
		if (!tmp)
		{
			ft_lstclear(&f_lst, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&f_lst, tmp);
	}
	return (f_lst);
}
