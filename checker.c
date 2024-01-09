/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 16:53:53 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/08 10:19:05 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	check_format(char *c)
{
	if (!ft_strncmp(c, "pa\n", 4))
		return (true);
	else if (!ft_strncmp(c, "pb\n", 4))
		return (true);
	else if (!ft_strncmp(c, "ra\n", 4))
		return (true);
	else if (!ft_strncmp(c, "rb\n", 4))
		return (true);
	else if (!ft_strncmp(c, "rr\n", 4))
		return (true);
	else if (!ft_strncmp(c, "rra\n", 5))
		return (true);
	else if (!ft_strncmp(c, "rrb\n", 5))
		return (true);
	else if (!ft_strncmp(c, "rrr\n", 5))
		return (true);
	else if (!ft_strncmp(c, "sa\n", 4))
		return (true);
	else if (!ft_strncmp(c, "sb\n", 4))
		return (true);
	else if (!ft_strncmp(c, "ss\n", 4))
		return (true);
	return (false);
}

void	read_operations(t_list **list, t_stack **a)
{
	char	*operation;
	t_list	*new_node;
	bool	corect_format;

	operation = get_next_line(0);
	while (operation)
	{
		corect_format = check_format(operation);
		if (!corect_format)
			bonus_exit(a, list, operation);
		new_node = ft_lstnew(operation);
		if (!new_node)
			bonus_exit(a, list, operation);
		ft_lstadd_back(list, new_node);
		operation = get_next_line(0);
	}
}

void	exec_rr_s(char *op, t_stack **a, t_stack **b)
{
	if (!ft_strncmp(op, "rra\n", 5))
		reverse_rotate(a);
	else if (!ft_strncmp(op, "rrb\n", 5))
		reverse_rotate(b);
	else if (!ft_strncmp(op, "rrr\n", 5))
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else if (!ft_strncmp(op, "sa\n", 4))
		swap(a);
	else if (!ft_strncmp(op, "sb\n", 4))
		swap(b);
	else
	{
		swap(a);
		swap(b);
	}
}

void	execute_operations(t_list *list, t_stack **a, t_stack **b)
{
	char	*op;

	while (list)
	{
		op = list->content;
		if (!ft_strncmp(op, "pa\n", 4))
			push(a, b);
		else if (!ft_strncmp(op, "pb\n", 4))
			push(b, a);
		else if (!ft_strncmp(op, "ra\n", 4))
			rotate(a);
		else if (!ft_strncmp(op, "rb\n", 4))
			rotate(b);
		else if (!ft_strncmp(op, "rr\n", 4))
		{
			rotate(a);
			rotate(b);
		}
		else
			exec_rr_s(op, a, b);
		list = list->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*operations;

	if (argc < 2)
		return (2);
	stack_a = NULL;
	stack_b = NULL;
	operations = NULL;
	parse_arguments(argc, argv, &stack_a);
	read_operations(&operations, &stack_a);
	execute_operations(operations, &stack_a, &stack_b);
	if (stack_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&operations, del);
	ft_stkclear(&stack_a);
	ft_stkclear(&stack_b);
	return (1);
}
