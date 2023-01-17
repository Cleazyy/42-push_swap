/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:16:54 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/17 11:41:38 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	args_is_digits(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
    while (i < ac) 
	{
		j = 0;
        while (av[i][j]) 
		{
            if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
        }
		i++;
    }
	return (1);
}

int	check_args(int ac, char **av)
{
	if (ac < 2)
		return (print_error());
	else if (ac > 2)
		return (args_is_digits(ac, av));
	return (1);
}
