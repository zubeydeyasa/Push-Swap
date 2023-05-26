/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zyasa <zyasa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 14:25:11 by zyasa             #+#    #+#             */
/*   Updated: 2023/05/26 14:25:12 by zyasa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_stack *a, t_stack *b)
{
	swap(a, NULL);
	swap(b, NULL);
	write(1, "ss\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a, NULL);
	rotate(b, NULL);
	write(1, "rr\n", 3);
}

void	rrr(t_stack *a, t_stack *b)
{
	reverserotate(a, NULL);
	reverserotate(b, NULL);
}
