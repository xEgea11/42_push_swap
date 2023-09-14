/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 11:11:26 by regea-go          #+#    #+#             */
/*   Updated: 2023/08/28 18:59:50 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Sets last node as first (reverse rotate) - list a
 * 
 */
void	ft_dll_reverse_rotate_a(t_dllist **list, int flag)
{
	if (is_empty(*list) == TRUE || ft_dll_size(*list) == 1)
		return ;
	ft_not_first_node(*list);
	*list = (*list)->prev;
	ft_is_first_node(*list);
	if (flag == 1)
		ft_printf("rra\n");
	return ;
}

/**
 * @brief Sets last node as first (reverse rotate) - list b
 * 
 */
void	ft_dll_reverse_rotate_b(t_dllist **list, int flag)
{
	if (is_empty(*list) == TRUE || ft_dll_size(*list) == 1)
		return ;
	ft_not_first_node(*list);
	*list = (*list)->prev;
	ft_is_first_node(*list);
	if (flag == 1)
		ft_printf("rrb\n");
	return ;
}

/**
 * @brief Reverse rotates both lists
 * 
 * @param a 
 * @param b 
 */
void	ft_dll_reverse_rotate_a_b(t_dllist **a, t_dllist **b)
{
	ft_dll_reverse_rotate_a(a, 0);
	ft_dll_reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
	return ;
}
