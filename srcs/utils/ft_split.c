/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluchten <fluchten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 09:26:44 by fluchten          #+#    #+#             */
/*   Updated: 2023/01/21 14:25:39 by fluchten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**init_splits(char **final, const char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (s[i])
				count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	final = malloc(sizeof(char *) * (count + 1));
	if (!final)
		return (NULL);
	return (final);
}

static char	*fill_splits(const char *s, char c)
{
	char	*final;
	size_t	len;
	size_t	i;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	final = malloc(sizeof(char) * (len + 1));
	if (!final)
		return (NULL);
	i = 0;
	while (i < len)
	{
		final[i] = s[i];
		i++;
	}
	final[i] = '\0';
	return (final);
}

static char	**free_splits(char **final, size_t j)
{
	while (j >= 0)
	{
		free(final[j]);
		j--;
	}
	free(final);
	return (0);
}

static char	**allocate_splits(char **final, const char *s, char c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			final[j] = fill_splits(&s[i], c);
			if (!final[j])
				return (free_splits(final, j));
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	final[j] = NULL;
	return (final);
}

char	**ft_split(const char *s, char c)
{
	char	**final;

	final = NULL;
	final = init_splits(final, s, c);
	final = allocate_splits(final, s, c);
	return (final);
}
