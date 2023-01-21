/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/21 14:49:56 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ac < 2)
		exit_error();
	if (ac == 2)
		stack_a = init_stack(ac, ft_split(av[1], ' '));
	else
		stack_a = init_stack(ac, av);
	stack_b = NULL;
	print_stack(stack_a);
	sort(&stack_a, &stack_b);
	print_stack(stack_a);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
