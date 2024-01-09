/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:01:37 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/05 17:59:56 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_target_to_a(t_stack *a, t_stack *to_move)
{
	t_stack	*target;
	t_stack	*min_a;

	target = NULL;
	min_a = a;
	while (a)
	{
		if (a->num == to_move->num + 1)
			return (a->index);
		if (a->num > to_move->num)
		{
			if (!target)
				target = a;
			else if (a->num < target->num)
				target = a;
		}
		if (a->num < min_a->num)
			min_a = a;
		a = a->next;
	}
	if (!target)
		target = min_a;
	return (target->index);
}

void	push_b_to_a(t_stack **a, t_stack **b, int *size_a, int *size_b)
{
	int	index_a;

	sort_three(a);
	set_indexes(a, b);
	index_a = set_target_to_a(*a, *b);
	rotate_target(a, index_a, *size_a);
	pa(a, b);
	(*size_a)++;
	(*size_b)--;
}
