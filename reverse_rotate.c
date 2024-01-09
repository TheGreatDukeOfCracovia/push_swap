/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 17:35:46 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/03 17:36:43 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*penultimate;
	t_stack	*last;

	if (!stack)
		return ;
	if (!*stack)
		return ;
	if (!(*stack)->next)
		return ;
	penultimate = *stack;
	while (penultimate->next->next)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->prev = NULL;
	ft_stkadd_front(stack, last);
}

void	rra(t_stack **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
