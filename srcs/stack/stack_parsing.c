/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:47:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 19:57:11 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(char *content)
{
	t_stack	*element;
	int		invalid_nb;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->content = convert_number(content, &invalid_nb);
	if (invalid_nb == 1)
	{
		free(element);
		return (0);
	}
	element->next = NULL;
	return (element);
}

static void	args_stack(int ac, char **av, int *i, t_stack **stack_a)
{
	if (ac == 2)
	{
		*stack_a = new_stack(av[0]);
		if (!*stack_a)
			exit_free_stack(*stack_a, 1);
		*i = 1;
	}
	else
	{
		*stack_a = new_stack(av[1]);
		if (!*stack_a)
			exit_free_stack(*stack_a, 1);
		*i = 2;
	}
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int		i;

	args_stack(ac, av, &i, &stack_a);
	temp = stack_a;
	while (av[i])
	{
		temp->next = new_stack(av[i]);
		if (!temp->next)
			exit_free_stack(stack_a, 1);
		temp = temp->next;
		i++;
	}
	check_valid_stack(stack_a);
	return (stack_a);
}
