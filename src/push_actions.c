/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:21:37 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 14:53:46 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief 
 * 
 * @param list 
 * @param node 
 */
void	ft_push_if_1(t_dllist **list, t_dllist *node)
{
	(*list)->prev = node;
	(*list)->next = node;
	node->next = *list;
	node->prev = *list;
	ft_not_first_node(*list);
	*list = (*list)->prev;
	ft_is_first_node(*list);
}

/**
 * @brief Inserts a node in the first position of a list
 * 
 * @param list 
 * @param node 
 */
void	ft_dll_push(t_dllist **list, t_dllist *node)
{
	if (node == NULL)
		return ;
	else if (is_empty(*list))
	{
		*list = node;
		node->next = node;
		node->prev = node;
		ft_is_first_node(*list);
		return ;
	}
	else if (ft_dll_size(*list) == 1)
		return (ft_push_if_1(list, node));
	else
	{
		ft_not_first_node(*list);
		(*list)->prev->next = node;
		node->next = *list;
		node->prev = (*list)->prev;
		(*list)->prev = node;
		*list = (*list)->prev;
		ft_is_first_node(*list);
		return ;
	}
}

/**
 * @brief Puts first elem of a into b
 * 
 * @param list_a    List where we take the element
 * @param list_b   List where we put element 
 */
void	ft_dll_push_b(t_dllist **list_a, t_dllist **list_b)
{
	if (*list_a == NULL)
		return ;
	ft_dll_push(list_b, ft_dll_pop(list_a));
	ft_printf("pb\n");
}

/**
 * @brief Puts first elem of b into a
 * 
 * @param list_b    List where we take the element
 * @param list_a   List where we put element 
 */
void	ft_dll_push_a(t_dllist **list_b, t_dllist **list_a)
{
	t_dllist	*node;

	if (*list_b == NULL)
		return ;
	node = ft_dll_pop(list_b);
	ft_dll_push(list_a, node);
	ft_printf("pa\n");
}
