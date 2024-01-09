/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:05:40 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/05 21:26:25 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_duplicate(int to_check, t_stack **stack, char **tab)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (to_check == tmp->num)
			free_and_exit(stack, NULL, NULL, tab);
		tmp = tmp->next;
	}
}

int	convert_chars(char *nptr, t_stack **stack, char **tab)
{
	int			i;
	int			sign;
	int			digits_here;
	long int	number;

	i = 0;
	sign = 1;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	digits_here = 0;
	number = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		digits_here = 1;
		number = number * 10 + nptr[i] - '0';
		i++;
	}
	number *= sign;
	if ((nptr[i] || !digits_here) || (number < INT_MIN || number > INT_MAX))
		free_and_exit(stack, NULL, NULL, tab);
	return ((int) number);
}

void	numbers_to_stack(char *digits, t_stack **stack, char **tab)
{
	t_stack	*new_node;
	int		number;

	number = convert_chars(digits, stack, tab);
	check_duplicate(number, stack, tab);
	new_node = ft_stknew(number);
	if (!new_node)
		free_and_exit(stack, NULL, NULL, tab);
	ft_stkadd_back(stack, new_node);
}

void	free_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	parse_arguments(int argc, char **argv, t_stack **stack)
{
	char	**numbers_tab;
	int		arg_num;
	int		i;
	int		j;

	i = 1;
	arg_num = 0;
	while (i < argc)
	{
		numbers_tab = ft_split(argv[i], ' ');
		if (!numbers_tab)
			free_and_exit(stack, NULL, NULL, numbers_tab);
		j = 0;
		while (numbers_tab[j])
		{
			numbers_to_stack(numbers_tab[j], stack, numbers_tab);
			arg_num++;
			j++;
		}
		if (!j)
			free_and_exit(stack, NULL, NULL, numbers_tab);
		free_tab(numbers_tab);
		i++;
	}
	return (arg_num);
}
