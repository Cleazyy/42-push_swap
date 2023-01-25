/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:47:47 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/25 12:11:44 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	exit_free_stack(t_stack *stack, int error)
{
	free_stack(stack);
	if (!error)
		exit(EXIT_SUCCESS);
	else
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}	
}

static int	error_number(int *error)
{
	*error = 1;
	return (0);
}

int	ft_atoi(const char *str, int *error)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	*error = 0;
	if (!str)
		return (error_number(error));
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - 48);
		if (sign * res < INT_MIN || sign * res > INT_MAX)
			return (error_number(error));
	}
	if (str[i])
		return (error_number(error));
	return (sign * res);
}
