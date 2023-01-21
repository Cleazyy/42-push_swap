/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:47:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/21 15:25:58 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(char *content)
{
	t_stack	*element;

	if (!is_valid_number(content))
		exit_error();
	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->content = ft_atoi(content);
	element->next = NULL;
	return (element);
}

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*temp;
	int		i;

	if (ac == 2)
	{
		stack_a = new_stack(av[0]);
		i = 1;
	}
	else
	{
		stack_a = new_stack(av[1]);
		i = 2;
	}
	temp = stack_a;
	while (av[i])
	{
		temp->next = new_stack(av[i]);
		temp = temp->next;
		i++;
	}
	check_valid_stack(stack_a);
	return (stack_a);
}
