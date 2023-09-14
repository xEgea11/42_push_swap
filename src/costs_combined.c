/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_combined.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:15:14 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 13:50:31 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Aux function to init costs 
 * 
 * @return t_cost* 
 */
static t_cost	*init_costs(void)
{
	t_cost	*costs;

	costs = malloc(sizeof(t_cost));
	if (!costs)
		return (NULL);
	costs->cost_a = MAX_INT;
	costs->cost_b = MAX_INT;
	costs->steps = MAX_INT;
	return (costs);
}

/**
 * @brief Calculates the steps in a for every node in b; return combined cost
 * 
 * @param a 
 * @param b 
 * @return t_cost* 
 */
t_cost	*ft_combined(t_dllist *a, t_dllist *b)
{
	t_cost		*costs;
	t_dllist	*itr;
	int			start;
	int			combined;

	start = 0;
	costs = init_costs();
	if (!costs)
		return (NULL);
	combined = 0;
	itr = b;
	while (itr->head != 1 || start == 0)
	{
		combined = ab(count_steps(a, itr->index)) + ab(steps(b, itr->index));
		if (start == 0)
			start = 1;
		if (combined < costs->steps)
		{
			costs->cost_a = count_steps(a, itr->index);
			costs->cost_b = steps(b, itr->index);
			costs->steps = combined;
		}
		itr = itr->next;
	}
	return (costs);
}
