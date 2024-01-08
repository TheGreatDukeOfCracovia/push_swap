/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_sup_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 00:22:50 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/05 00:29:12 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lower(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_superior(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	set_indexes(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	if (a)
	{
		tmp = *a;
		while (tmp)
		{
			tmp->index = i;
			i++;
			tmp = tmp->next;
		}
	}
	i = 0;
	if (b)
	{
		tmp = *b;
		while (tmp)
		{
			tmp->index = i;
			i++;
			tmp = tmp->next;
		}
	}
}

void	rotate_target(t_stack **a, int index_a, int size_a)
{
	if (index_a <= size_a - index_a)
	{
		while (index_a)
		{
			ra(a);
			index_a--;
		}
	}
	else
	{
		while (size_a - index_a)
		{
			rra(a);
			size_a--;
		}
	}
}
