/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:25:26 by zyasa             #+#    #+#             */
/*   Updated: 2023/05/26 14:25:27 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	find_min (t_stack *stack, int *index)
{
	int	i;
	int	min;

	min = 2147483647;
	i = 0;
	while (i < stack->size)
	{
		if (stack->numbers[i].number < min && stack->numbers[i].index == -1)
			min = stack->numbers[i].number;
		i++;
	}
	i = 0;
	while (i < stack->size)
	{
		if (stack->numbers[i].number == min)
		{
			stack->numbers[i].index = *index;
			(*index)++;
			return ;
		}
		i++;
	}
}

void	index_numbers(t_stack *stack)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (i < stack->size)
	{
		find_min(stack, &index);
		i++;
	}
}
