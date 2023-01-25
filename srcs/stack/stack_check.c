/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:25:01 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 11:27:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_stack_duplicate(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		while (temp)
		{
			if (stack->content == temp->content)
				return (1);
			temp = temp->next;
		}
		stack = stack->next;
	}
	return (0);
}

static int	check_stack_is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	check_valid_stack(t_stack *stack)
{
	if (check_stack_duplicate(stack))
		exit_free_stack(stack, 1);
	else if (check_stack_is_sorted(stack))
		exit_free_stack(stack, 0);
}
