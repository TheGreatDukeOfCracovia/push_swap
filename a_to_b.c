/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:21:21 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/05 18:21:47 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*set_target_to_b(t_stack *to_fill, t_stack *b)
{
	t_stack	*target;
	t_stack	*max_b;

	target = NULL;
	max_b = b;
	while (b)
	{
		if (b->num == to_fill->num - 1)
			return (b);
		if (b->num < to_fill->num)
		{
			if (!target)
				target = b;
			else if (b->num > target->num)
				target = b;
		}
		if (b->num > max_b->num)
			max_b = b;
		b = b->next;
	}
	if (!target)
		target = max_b;
	return (target);
}

void	execute_path_to_b(t_stack **a, t_stack **b, t_stack *to_move)
{
	t_move	*plan;

	plan = to_move->move;
	while (plan)
	{
		while (plan->count > 0)
		{
			if (plan->op_id == 1)
				ra(a);
			if (plan->op_id == 2)
				rb(b);
			if (plan->op_id == 3)
				rr(a, b);
			if (plan->op_id == 4)
				rra(a);
			if (plan->op_id == 5)
				rrb(b);
			if (plan->op_id == 6)
				rrr(a, b);
			plan->count--;
		}
		plan = plan->next;
	}
	pb(a, b);
}

void	push_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*index;
	t_stack	*to_push;

	set_indexes(a, b);
	index = *a;
	to_push = *a;
	while (index)
	{
		index->target = set_target_to_b(index, *b);
		if (index->move)
			ft_mvclear(&index->move);
		index->move = set_move_path(index, a, b);
		if (index->move->total < 2)
		{
			execute_path_to_b(a, b, index);
			return ;
		}
		if (index->move->total < to_push->move->total)
			to_push = index;
		index = index->next;
	}
	execute_path_to_b(a, b, to_push);
}
