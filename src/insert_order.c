/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 11:37:39 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/07 11:37:58 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Function used at the beggining of the order procedure - 
 * 			We start at a = 2 and b = rest
 * 		- It swaps values in a if not sorted
 * 		- Then it pushes all the values from b to a, sorted
 * 
 * @param a 
 * @param b 
 */
int	ft_insert_in_order(t_dllist **a, t_dllist **b)
{
	t_dllist	*itr;
	t_dllist	*itr_b;
	t_cost		*combined;

	combined = NULL;
	itr = *a;
	itr_b = *b;
	if (ft_dll_size(*a) == 2)
		ft_push_swap_2(a);
	while (!is_empty(*b))
	{
		itr = *a;
		itr_b = *b;
		combined = ft_combined(itr, itr_b);
		if (!combined)
			return (FALSE);
		ft_shortest_rotation_a(a, combined->cost_a);
		ft_shortest_rotation_b(b, combined->cost_b);
		ft_dll_push_a(b, a);
		free(combined);
	}
	ft_order_list(a);
	return (TRUE);
}
