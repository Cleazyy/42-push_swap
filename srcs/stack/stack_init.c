/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 07:47:15 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/18 07:52:24 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*new_stack(char *content)
{
	t_stack	*element;

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

	stack_a = new_stack(av[1]);
	temp = stack_a;
	i = 2;
	while (i < ac)
	{
		temp->next = new_stack(av[i]);
		temp = temp->next;
		i++;
	}
	if (check_stack_duplicate(stack_a))
		free_stack_error(stack_a);
	if (check_stack_is_sorted(stack_a))
		free_stack_error(stack_a);
	return (stack_a);
}
