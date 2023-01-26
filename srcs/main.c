/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:23 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/26 10:53:52 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**array;

	if (!check_args(ac, av))
		return (0);
	if (ac == 2)
	{
		array = ft_split(av[1], ' ');
		stack_a = init_stack(ac, array);
		free_array(array);
	}
	else
		stack_a = init_stack(ac, av);
	stack_b = NULL;
	sort(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
