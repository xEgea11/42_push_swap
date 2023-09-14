/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 15:19:01 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/07 10:59:31 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Sets second node as first (the first one goes last) - list a
 * 
 * @param list 
 * @param flag - sets to 1 if you want to print the action, 0 if not
 */
void	ft_dll_rotate_a(t_dllist **list, int flag)
{
	if (!*list || ft_dll_size(*list) == 1)
		return ;
	ft_not_first_node(*list);
	*list = (*list)->next;
	ft_is_first_node(*list);
	if (flag == 1)
		ft_printf("ra\n");
	return ;
}

/**
 * @brief Sets second node as first (the first one goes last) - list b
 * 
 * @param list 
 * @param flag - sets to 1 if you want to print the action, 0 if not
 */
void	ft_dll_rotate_b(t_dllist **list, int flag)
{
	if (!*list || ft_dll_size(*list) == 1)
		return ;
	ft_not_first_node(*list);
	*list = (*list)->next;
	ft_is_first_node(*list);
	if (flag == 1)
		ft_printf("rb\n");
	return ;
}

/**
 * @brief Rotates both lists
 * 
 */
void	ft_dll_rotate_a_b(t_dllist **a, t_dllist **b)
{
	ft_dll_rotate_a(a, 0);
	ft_dll_rotate_b(b, 0);
	ft_printf("rr\n");
	return ;
}
