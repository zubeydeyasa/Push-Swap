/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:23:13 by zyasa             #+#    #+#             */
/*   Updated: 2023/05/26 14:24:55 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_number
{
	int	number;
	int	index;
}	t_number;

typedef struct s_stack
{
	t_number	*numbers;
	int			size;
	int			capacity;
}	t_stack;

void	error(void);
void	ft_control(char *str);
int		ft_inline(t_stack a);
void	swap(t_stack *stack, char *print);
void	rotate(t_stack *stack, char *print);
void	reverserotate(t_stack *stack, char *print);
void	push(t_stack *sender, t_stack *receiver, char *print);
void	ss(t_stack *a, t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rrr(t_stack *a, t_stack *b);
void	index_numbers(t_stack *stack);
void	if_same(t_stack a, int number);
void	radix(t_stack *a, t_stack *b);
void	mini_sort(t_stack *a, t_stack *b);

#endif