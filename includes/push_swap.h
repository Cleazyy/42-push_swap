/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:51 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/21 15:25:19 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // TO DELETE

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

/* args */
int		check_args(int ac, char **av);
/* stack */
t_stack	*init_stack(int ac, char **av);
void	free_stack(t_stack *stack);
int		stack_len(t_stack *stack);
int		stack_smallest_element(t_stack *stack, int *index);
void	print_stack(t_stack *stack);
void	check_valid_stack(t_stack *stack);
/* sort */
void	sort(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack_a);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
/* operations */
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
/* utils */
void	exit_error(void);
void	free_stack_error(t_stack *stack);
int		ft_isdigit(int c);
int		is_valid_number(const char *str);
int		ft_atoi(const char *str);
char	**ft_split(const char *s, char c);

#endif