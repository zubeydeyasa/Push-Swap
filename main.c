/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:25:29 by zyasa             #+#    #+#             */
/*   Updated: 2023/05/26 14:25:30 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	strs_free (char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void	add_numbers (t_stack *a, char **av)
{
	int		i;
	int		j;
	int		k;
	long	curr;
	char	**strs;

	k = 0;
	i = 1;
	while (av[i])
	{
		if (av[i][0] == '\0' || av[i][0] == ' ' || av[i][0] == '\t')
			error();
		strs = ft_split(av[i], ' ');
		j = 0;
		while (strs[j])
		{
			ft_control(strs[j]);
			curr = ft_atol(strs[j]);
			if (curr > 2147483647 || curr < -2147483648)
				error();
			if_same(*a, curr);
			a->numbers[k].number = curr;
			a->numbers[k].index = -1;
			a->size++;
			k++;
			j++;
		}
		strs_free(strs);
		i++;
	}
}

int	number_count (char **av)
{
	int	capacity;
	int	j;
	int	i;
	char	**strs;

	i = 1;
	capacity = 0;
	while (av[i])
	{
		j = 0;
		strs = ft_split(av[i], ' ');
		while (strs[j])
		{
			capacity++;
			j++;
		}
		strs_free(strs);
		i++;
	}
	return (capacity);
}

void	init_stacks (t_stack *a, t_stack *b, char **av)
{
	a->capacity = number_count(av);
	b->capacity = a->capacity;
	a->numbers = malloc(sizeof(t_number) * a->capacity);
	b->numbers = malloc(sizeof(t_number) * a->capacity);
	a->size = 0;
	b->size = 0;
	add_numbers(a, av);
}

int	main (int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	if (ac > 1)
	{
		init_stacks(&a, &b, av);
		if (ac == 2)
			return (0);
		if (ft_inline(a))
			exit(0);
		index_numbers(&a);
		if (a.size < 6)
			mini_sort(&a, &b);
		else
			radix(&a, &b);
		for (int i = 0; i < a.size; i++)
		{
			printf("%d\n", a.numbers[i].index);
		}
	}
	return (0);
}
