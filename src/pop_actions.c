/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:52:42 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 14:53:00 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Aux to set the pointers correctly in order to pop a element
 * 
 * @param list 
 * @param node 
 * @return t_dllist* 
 */
static t_dllist	*ft_pop(t_dllist **list, t_dllist *node)
{
	(*list)->prev->next = (*list)->next;
	(*list)->next->prev = (*list)->prev;
	ft_not_first_node(*list);
	*list = (*list)->next;
	ft_is_first_node(*list);
	node->next = NULL;
	node->prev = NULL;
	ft_not_first_node(node);
	return (node);
}

/**
 * @brief Pops the first node from a list; then sets the next node as head
 * 
 * @param list 
 * @return t_dllist* the first node of the list
 */
t_dllist	*ft_dll_pop(t_dllist **list)
{
	t_dllist	*node;

	if (is_empty(*list))
		return (NULL);
	if (ft_dll_size(*list) == 1)
	{
		node = *list;
		ft_not_first_node(node);
		*list = NULL;
		return (node);
	}
	else
	{
		node = *list;
		return (ft_pop(list, node));
	}
}
