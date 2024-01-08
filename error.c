/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 18:20:25 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/08 10:20:08 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *to_del)
{
	if (to_del)
	{
		free(to_del);
		to_del = NULL;
	}
}

void	bonus_exit(t_stack **a, t_list **list, char *c)
{
	if (c)
	{
		free(c);
		c = NULL;
	}
	ft_stkclear(a);
	ft_lstclear(list, del);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}

void	free_and_exit(t_stack **a, t_stack **b, t_move **c, char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
	ft_stkclear(a);
	ft_stkclear(b);
	ft_mvclear(c);
	write(2, "Error\n", 6);
	exit (EXIT_FAILURE);
}
