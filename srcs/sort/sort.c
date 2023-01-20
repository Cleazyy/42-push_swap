/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:19:05 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/20 11:49:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	(void) stack_b;
	len = stack_len(*stack_a);
	if (len == 2)
		sa(stack_a);
	else if (len == 3)
		sort_three(stack_a);
	else if (len == 5)
		sort_five(stack_a, stack_b);
	else
		printf("in progress\n");
}
