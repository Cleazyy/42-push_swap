/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 12:41:08 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/23 13:14:59 by fluchten         ###   ########.fr       */
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

	tab = malloc(sizeof(int) * (stack_len(*stack_a) + 1));
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
	int	size;
	int	i;
	int	j;

	tab = parsing_tab(stack_a, 1);
	tab_new = parsing_tab(stack_a, 0);
	size = stack_len(*stack_a);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tab_new[i] == tab[j])
				tab_new[i] = j;
			j++;
		}
		i++;
	}
	free(tab);
	put_tab_struct(tab_new, *stack_a);
}
