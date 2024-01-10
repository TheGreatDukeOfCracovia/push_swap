/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 23:29:16 by tde-la-r          #+#    #+#             */
/*   Updated: 2024/01/10 10:18:57 by tde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include <stdbool.h>
# include "libft/libft.h"

typedef struct s_move_path
{
	int					total;
	int					op_id;
	int					count;
	struct s_move_path	*next;
}					t_move;

typedef struct s_stack
{
	int				num;
	int				index;
	t_move			*move;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

typedef struct s_costs
{
	int	up_a;
	int	dn_a;
	int	up_b;
	int	dn_b;
	int	opposite;
	int	ascending;
	int	descending;
}		t_costs;

void	free_and_exit(t_stack **a, t_stack **b, t_move **c, char **tab);
void	bonus_exit(t_stack **a, t_list **list, char *c);
void	del(void *to_del);

int		parse_arguments(int argc, char **argv, t_stack **stack);
void	push_a_to_b(t_stack **a, t_stack **b);
void	push_b_to_a(t_stack **a, t_stack **b, int *size_a, int *size_b);
t_move	*set_move_path(t_stack *moving, t_stack **a, t_stack **b);

void	sort_three(t_stack **a);
t_stack	*find_min(t_stack *stack);
t_stack	*find_max(t_stack *stack);
bool	stack_sorted(t_stack *stack);
void	rotate_target(t_stack **a, int index_a, int size_a);
void	set_indexes(t_stack **a, t_stack **b);
int		ft_lower(int a, int b);
int		ft_superior(int a, int b);

void	push(t_stack **stack_in, t_stack **stack_out);
void	swap(t_stack **stack);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

t_stack	*ft_stknew(int num);
void	ft_stkadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stklast(t_stack *lst);
void	ft_stkadd_front(t_stack **lst, t_stack *new);
int		ft_stksize(t_stack *stk);
void	ft_stkclear(t_stack **lst);
void	ft_mvclear(t_move **lst);
t_move	*ft_mvnew(int total, int op_id, int count);
t_move	*ft_mvlast(t_move *lst);
void	ft_mvadd_back(t_move **lst, t_move *new);

#endif
