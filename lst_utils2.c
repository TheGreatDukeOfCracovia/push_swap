/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:44:34 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/05 00:51:17 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_move	*ft_mvnew(int total, int op_id, int count)
{
	t_move	*new_node;

	new_node = malloc(sizeof(t_move));
	if (!new_node)
		return (NULL);
	new_node->total = total;
	new_node->op_id = op_id;
	new_node->count = count;
	new_node->next = NULL;
	return (new_node);
}

t_move	*ft_mvlast(t_move *lst)
{
	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	return (ft_mvlast(lst->next));
}

void	ft_mvadd_back(t_move **lst, t_move *new)
{
	t_move	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_mvlast(*lst);
		last->next = new;
	}
}

void	ft_mvclear(t_move **lst)
{
	if (!lst)
		return ;
	if (!*lst)
		return ;
	if ((*lst)->next)
		ft_mvclear(&(*lst)->next);
	free(*lst);
	*lst = NULL;
}

void	ft_stkclear(t_stack **lst)
{
	if (!lst)
		return ;
	if (!*lst)
		return ;
	if ((*lst)->next)
		ft_stkclear(&(*lst)->next);
	ft_mvclear(&(*lst)->move);
	free(*lst);
	*lst = NULL;
}
