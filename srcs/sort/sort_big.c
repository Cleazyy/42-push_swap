/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:41:08 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/26 10:55:48 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	temp;

	while (size--)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] > tab[i + 1])
			{
				temp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = temp;
			}
			i++;
		}
	}
}

static int	*parsing_tab(t_stack **stack_a, int value)
{
	t_stack	*temp;
	int		*tab;
	int		i;

	tab = malloc(sizeof(int) * (stack_size(*stack_a) + 1));
	if (!tab)
		return (NULL);
	temp = (*stack_a);
	if (!temp)
		return (NULL);
	i = 0;
	while (temp)
	{
		tab[i] = temp->content;
		temp = temp->next;
		i++;
	}
	if (value == 1)
		sort_int_tab(tab, i);
	return (tab);
}

static void	put_tab_struct(int *tab, t_stack *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->content = tab[i];
		stack = stack->next;
		i++;
	}
	free(tab);
}

void	sort_struct(t_stack **stack_a)
{
	int	*tab_new;
	int	*tab;
	int	i;
	int	j;

	tab = parsing_tab(stack_a, 1);
	tab_new = parsing_tab(stack_a, 0);
	i = 0;
	while (i < stack_size(*stack_a))
	{
		j = 0;
		while (j < stack_size(*stack_a))
		{
			if (tab_new[i] == tab[j])
			{
				tab_new[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
	free(tab);
	put_tab_struct(tab_new, *stack_a);
}

void	sort_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	size;
	int	num;
	int	i;
	int	j;

	size = stack_size(*stack_a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			num = (*stack_a)->content;
			if (((num >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
