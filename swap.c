/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:35:02 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/03 17:35:09 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	if (!stack)
		return ;
	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	(*stack)->prev = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	(*stack)->prev->prev = NULL;
	(*stack)->prev->next = *stack;
	*stack = (*stack)->prev;
	if ((*stack)->next->next)
		(*stack)->next->next->prev = (*stack)->next;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
