/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:24:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/20 11:57:41 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	i;
	int	j;
	int	k;

	i = (*stack_a)->content;
	j = (*stack_a)->next->content;
	k = (*stack_a)->next->next->content;
	if (i < j && i < k && j > k)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (i > j && i < k && j < k)
		sa(stack_a);
	else if (i < j && i > k && j > k)
		rra(stack_a);
	else if (i > j && i > k && j < k)
		ra(stack_a);
	else if (i > j && i > k && j > k)
	{
		sa(stack_a);
		rra(stack_a);
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		min_pos;

	min = stack_smallest_element((*stack_a), &min_pos);
	while ((*stack_a)->content > min)
	{
		if (min_pos < (stack_len(*stack_a) / 2))
			ra(stack_a);
		else
			rra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		min_pos;
	int		i;

	i = 0;
	while (i < 2)
	{
		min = stack_smallest_element((*stack_a), &min_pos);
		while ((*stack_a)->content > min)
		{
			if (min_pos < (stack_len(*stack_a) / 2))
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}
