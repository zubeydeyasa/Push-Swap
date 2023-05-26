/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:25:47 by zyasa             #+#    #+#             */
/*   Updated: 2023/05/26 14:37:04 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap (t_stack *stack, char *print)
{
	int	temp;

	if (stack->size < 2)
		return ;
	temp = stack->numbers[1].index;
	stack->numbers[1].index = stack->numbers[0].index;
	stack->numbers[0].index = temp;
	if (print)
		write(1, print, 3);
}

void	rotate (t_stack *stack, char *print)
{
	int	temp;
	int	i;

	if (stack->size < 2)
		return ;
	i  = 0;
	temp = stack->numbers[0].index;
	while (i < stack->size - 1)
	{
		stack->numbers[i].index = stack->numbers[i + 1].index;
		i++;
	}
	stack->numbers[stack->size - 1].index = temp;
	if (print)
		write(1, print, 3);
}

void	reverserotate (t_stack *stack, char *print)
{
	int	temp;
	int	size;

	if (stack->size < 2)
		return ;
	temp =  stack->numbers[stack->size - 1].index;
	size = stack->size;
	while (size - 1 > 0)
	{
		stack->numbers[size - 1].index = stack->numbers[size - 2].index;
		size--;
	}
	stack->numbers[0].index = temp;
	if (print)
		write(1, print, 4);
}

void	push (t_stack *sender, t_stack *receiver, char *print)
{
	int	first;
	int	i;
	int	size;

	if (sender->size < 1)
		return ;
	size = receiver->size;
	i = 0;
	first = sender->numbers[0].index;
	while (i < sender->size - 1)
	{
		sender->numbers[i].index = sender->numbers[i + 1].index;
		i++;
	}
	while (size - 1 >= 0)
	{
		receiver->numbers[size].index = receiver->numbers[size - 1].index;
		size--;
	}
	receiver->numbers[0].index = first;
	sender->size--;
	receiver->size++;
	write (1, print, 3);
}
