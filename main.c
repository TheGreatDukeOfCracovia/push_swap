/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:34:38 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/06 17:10:30 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack(t_stack **a, t_stack **b, int size_a)
{
	int		size_b;
	t_stack	*min_a;

	if (size_a < 4)
		sort_three(a);
	if (stack_sorted(*a))
		return ;
	size_b = 0;
	while (size_a > 3 && size_b < 2)
	{
		pb(a, b);
		size_a--;
		size_b++;
	}
	while (size_a > 3)
	{
		push_a_to_b(a, b);
		size_a--;
		size_b++;
	}
	while (size_b)
		push_b_to_a(a, b, &size_a, &size_b);
	set_indexes(a, b);
	min_a = find_min(*a);
	rotate_target(a, min_a->index, size_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		arg_num;

	if (argc < 2)
		return (2);
	stack_a = NULL;
	stack_b = NULL;
	arg_num = parse_arguments(argc, argv, &stack_a);
	sort_stack(&stack_a, &stack_b, arg_num);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (1);
}
