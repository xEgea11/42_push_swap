/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:26:23 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/04 14:26:37 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief It dictates if a list should do a rotate or a reverse rotate
 * 
 * @param a - the list to calculate the movement
 * @param index - The position where the list has to rotate
 */
void	ft_economic_move(t_dllist **a, int index)
{
	if (ft_calculate_cost(*a, index, 0) > ft_dll_size(*a) / 2)
		ft_dll_reverse_rotate_a(a, 1);
	else
		ft_dll_rotate_a(a, 1);
}

/**
 * @brief - It put the beggining of the list in the node with lowest index
 * 
 * @param list 
 */
void	ft_order_list(t_dllist **list)
{
	t_dllist	*itr;

	itr = *list;
	while (itr->index != ft_find_min_idx(*list))
	{
		ft_economic_move(list, ft_find_min_idx(*list));
		itr = *list;
	}
}
