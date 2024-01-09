/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 21:01:32 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/05 01:24:18 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_costs	calculate_costs(t_stack *moving, t_stack *a, t_stack *b)
{
	t_costs	ct;
	int		size_a;
	int		fastest_a;
	int		size_b;
	int		fastest_b;

	size_a = ft_stksize(a);
	ct.up_a = moving->index;
	ct.dn_a = size_a - moving->index;
	size_b = ft_stksize(b);
	ct.up_b = moving->target->index;
	ct.dn_b = size_b - moving->target->index;
	fastest_a = ft_lower(ct.up_a, ct.dn_a);
	fastest_b = ft_lower(ct.up_b, ct.dn_b);
	ct.opposite = fastest_a + fastest_b;
	ct.ascending = ft_superior(ct.up_a, ct.up_b);
	ct.descending = ft_superior(ct.dn_a, ct.dn_b);
	return (ct);
}

bool	calculate_opposite(t_move **path, t_costs ct)
{
	t_move	*new_node;

	if (ct.up_a <= ct.dn_a)
	{
		new_node = ft_mvnew(ct.opposite, 1, ct.up_a);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
		new_node = ft_mvnew(ct.opposite, 5, ct.dn_b);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
	}
	else
	{
		new_node = ft_mvnew(ct.opposite, 4, ct.dn_a);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
		new_node = ft_mvnew(ct.opposite, 2, ct.up_b);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
	}
	return (true);
}

bool	calculate_ascending(t_move **path, t_costs ct)
{
	t_move	*new_node;

	if (ct.up_a <= ct.up_b)
	{
		new_node = ft_mvnew(ct.ascending, 3, ct.up_a);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
		new_node = ft_mvnew(ct.ascending, 2, ct.up_b - ct.up_a);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
	}
	else
	{
		new_node = ft_mvnew(ct.ascending, 3, ct.up_b);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
		new_node = ft_mvnew(ct.ascending, 1, ct.up_a - ct.up_b);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
	}
	return (true);
}

bool	calculate_descending(t_move **path, t_costs ct)
{
	t_move	*new_node;

	if (ct.dn_a <= ct.dn_b)
	{
		new_node = ft_mvnew(ct.descending, 6, ct.dn_a);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
		new_node = ft_mvnew(ct.descending, 5, ct.dn_b - ct.dn_a);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
	}
	else
	{
		new_node = ft_mvnew(ct.descending, 6, ct.dn_b);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
		new_node = ft_mvnew(ct.descending, 4, ct.dn_a - ct.dn_b);
		if (!new_node)
			return (false);
		ft_mvadd_back(path, new_node);
	}
	return (true);
}

t_move	*set_move_path(t_stack *moving, t_stack **a, t_stack **b)
{
	t_costs	ct;
	t_move	*path;

	ct = calculate_costs(moving, *a, *b);
	path = NULL;
	if (ct.ascending <= ct.descending && ct.ascending <= ct.opposite)
	{
		if (!calculate_ascending(&path, ct))
			free_and_exit(a, b, &path, NULL);
		return (path);
	}
	else if (ct.descending <= ct.opposite)
	{
		if (!calculate_descending(&path, ct))
			free_and_exit(a, b, &path, NULL);
		return (path);
	}
	else
	{
		if (!calculate_opposite(&path, ct))
			free_and_exit(a, b, &path, NULL);
		return (path);
	}
	return (path);
}
