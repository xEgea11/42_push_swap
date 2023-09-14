/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shortest_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:21:00 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 18:21:30 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Decides if list a has to rotate or reverse rotate, 
 * 			depending of the shortest path
 * 
 * @param a 
 * @param cost_a - Number of steps to reach a point on the list 
 * 					* Negative --> reverse rotate
 * 					* Positive --> rotate
 */
void	ft_shortest_rotation_a(t_dllist **a, int cost_a)
{
	if (cost_a < 0)
	{
		while (cost_a < 0)
		{
			ft_dll_reverse_rotate_a(a, 1);
			cost_a++;
		}
	}
	else if (cost_a > 0)
	{
		while (cost_a > 0)
		{
			ft_dll_rotate_a(a, 1);
			cost_a--;
		}
	}
}

/**
 * @brief - Decides if list b has to rotate or reverse rotate, 
 * 			depending of the shortest path
 * 
 * @param b 
 * @param cost_b - Number of steps to reach a point on the list 
 * 					* Negative --> reverse rotate
 * 					* Positive --> rotate
 */
void	ft_shortest_rotation_b(t_dllist **b, int cost_b)
{
	if (cost_b < 0)
	{
		while (cost_b < 0)
		{
			ft_dll_reverse_rotate_b(b, 1);
			cost_b++;
		}
	}
	else if (cost_b > 0)
	{
		while (cost_b > 0)
		{
			ft_dll_rotate_b(b, 1);
			cost_b--;
		}
	}
}
