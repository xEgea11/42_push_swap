/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:20:29 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 12:24:25 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Swaps 2 first elements of a list - list a  
 * 		--- it swaps their values, not their pointers !!
 * 			we should do it better!!			
 * 
 * @param list 
 * @param flag - sets to 1 if you want to print the action, 0 if not
 */
void	ft_swap_a(t_dllist **list, int flag)
{
	t_dllist	*node;
	int			temp;
	int			index;

	if (ft_dll_size(*list) < 2)
		return ;
	node = *list;
	temp = node->data;
	index = node->index;
	node->data = node->next->data;
	node->index = node->next->index;
	node->next->data = temp;
	node->next->index = index;
	if (flag == 1)
		ft_printf("sa\n");
}

/**
 * @brief Swaps 2 first elements of a list - list b
 * 
 * @param list 
 * @param flag - sets to 1 if you want to print the action, 0 if not
 */
void	ft_swap_b(t_dllist **list, int flag)
{
	t_dllist	*node;
	int			temp;
	int			index;

	if (ft_dll_size(*list) < 2)
		return ;
	node = *list;
	temp = node->data;
	index = node->index;
	node->data = node->next->data;
	node->index = node->next->index;
	node->next->data = temp;
	node->next->index = index;
	if (flag == 1)
		ft_printf("sb\n");
}

/**
 * @brief Invokes swap in both of lists
 * 
 * @param list_a 
 * @param list_b 
 */
void	ft_swap_a_b(t_dllist **list_a, t_dllist **list_b)
{
	ft_swap_a(list_a, 0);
	ft_swap_b(list_b, 0);
	ft_printf("ss\n");
}
