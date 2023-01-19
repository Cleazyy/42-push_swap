/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_little.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:24:26 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/19 12:31:56 by fluchten         ###   ########.fr       */
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
	if (i < j && i < k && j > k) // 1 3 2
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (i > j && i < k && j < k) // 2 1 3
		sa(stack_a);
	else if (i < j && i > k && j > k) // 2 3 1
		rra(stack_a);
	else if (i > j && i > k && j < k) // 3 1 2
		ra(stack_a);
	else if (i > j && i > k && j > k) // 3 2 1
	{
		sa(stack_a);
		rra(stack_a);
	}
}
