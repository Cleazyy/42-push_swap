/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 08:37:16 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/20 11:49:36 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	stack_smallest_element(t_stack *stack, int *index)
{
	int	min;
	int	min_pos;
	int	i;

	i = 0;
	min_pos = 0;
	min = stack->content;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			min_pos = i;
		}
		stack = stack->next;
		i++;
	}
	*(index) = min_pos;
	return (min);
}

void	print_stack(t_stack *stack)
{
	if (!stack)
	{
		printf("The list is empty!\n");
		return ;
	}
	while (stack)
	{
		printf("\033[0;31m[%d] \033[0m", stack->content);
		stack = stack->next;
	}
	printf("\n");
}
