/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 14:31:23 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/09 18:46:54 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	stack_sorted(t_stack *stack)
{
	if (!stack)
		return (true);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack	*find_min(t_stack *stack)
{
	t_stack	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (min->num > stack->num)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

t_stack	*find_max(t_stack *stack)
{
	t_stack	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (max->num < stack->num)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

void	sort_three(t_stack **a)
{
	if (!(*a)->next)
		return ;
	if (!(*a)->next->next)
	{
		if ((*a)->num > (*a)->next->num)
			sa(a);
		return ;
	}
	if (find_max(*a) == *a)
		ra(a);
	else if (find_max(*a) == (*a)->next)
		rra(a);
	if ((*a)->num > (*a)->next->num)
		sa(a);
}
