/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:47:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/22 10:53:55 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	free_stack_error(t_stack *stack)
{
	free_stack(stack);
	exit_error();
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
