/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:33:48 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/10 10:20:52 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_in, t_stack **stack_out)
{
	t_stack	*tmp;

	if (!stack_out)
		return ;
	if (!*stack_out)
		return ;
	tmp = (*stack_out)->next;
	(*stack_out)->next = *stack_in;
	*stack_in = *stack_out;
	*stack_out = tmp;
}

void	pa(t_stack **a, t_stack **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	push(b, a);
	write(1, "pb\n", 3);
}
