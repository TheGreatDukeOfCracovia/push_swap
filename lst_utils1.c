/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:09:18 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/10 10:19:47 by tde-la-r         ###   ########.fr       */
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
