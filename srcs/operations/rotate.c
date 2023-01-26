/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 09:08:43 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/26 07:40:21 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **stack_a)
{
	t_stack	*head;
	t_stack	*temp;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	temp = *stack_a;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	head->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_stack **stack_b)
{
	t_stack	*head;
	t_stack	*temp;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	temp = *stack_b;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	head->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	write(1, "rr\n", 3);
}
