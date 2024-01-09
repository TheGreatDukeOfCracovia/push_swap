/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:18 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/05 00:13:15 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stknew(int num)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = 0;
	new_node->move = NULL;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_stklast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	if (!lst->next)
		return (lst);
	return (ft_stklast(lst->next));
}

void	ft_stkadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last;

	if (!new || !lst)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_stklast(*lst);
		new->prev = last;
		last->next = new;
	}
}

void	ft_stkadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!new || !lst)
		return ;
	tmp = *lst;
	*lst = new;
	new->next = tmp;
	if (tmp)
		tmp->prev = new;
}

int	ft_stksize(t_stack *stk)
{
	int		i;
	t_stack	*temp;

	if (!stk)
		return (0);
	if (!stk->next)
		return (1);
	temp = stk->next;
	i = 1;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}
