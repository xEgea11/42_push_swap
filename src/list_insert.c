/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_insert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:42:22 by regea-go          #+#    #+#             */
/*   Updated: 2023/08/26 20:40:21 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Sets the pointers properly between the inserted node 
 * 			and the list in the proper way
 * 
 * @param list 
 * @param node The node to insert
 */
static void	ft_link_node(t_dllist *list, t_dllist *node)
{
	node->next = list->next;
	node->prev = list;
	list->next = node;
	node->next->prev = node;
	ft_not_first_node(node);
}

/**
 * @brief creates a new node (list) -- sets head to 1 every single time
 * 
 * @param data number to store
 * @return t_dllist* returns the node created with the data stored in there; 
 * 			if failed, returns NULL
 */
t_dllist	*ft_new_dll(int data)
{
	t_dllist	*node;

	node = malloc(sizeof(t_dllist));
	if (!node)
		return (NULL);
	node->data = data;
	node->next = NULL;
	node->prev = NULL;
	node->head = 1;
	node->index = -1;
	return (node);
}

/**
 * @brief Configures a circular double linked list when 
 * 			a second node is to be inserted
 *        	Must be used only when 2 nodes are in the list 
 * 
 * @param list the list itself
 * @param node the new (second) node to be inserted
 * @return int TRUE if succeeded, FALSE if not
 */
int	ft_round_dllist(t_dllist **list, t_dllist *node)
{
	if (!*list)
		return (FALSE);
	ft_not_first_node(node);
	(*list)->next = node;
	(*list)->prev = node;
	node->next = *list;
	node->prev = *list;
	return (TRUE);
}

/**
 * @brief Inserts in the last position of a list the node passed as paramenter 
 * 
 * @param list 
 * @param node 
 * @return int  TRUE if it succeeed, FALSE if not
 */
int	ft_insert_back(t_dllist **list, t_dllist *node)
{
	t_dllist	*itr;

	if (!node)
		return (FALSE);
	if ((*list)->next == NULL && (*list)->prev == NULL)
	{
		if (ft_round_dllist(list, node) == FALSE)
		{
			free(node);
			return (FALSE);
		}
		else
			return (TRUE);
	}
	else
	{
		itr = ft_lastnode(*list);
		if (!itr)
			return (FALSE);
		ft_link_node(itr, node);
		return (TRUE);
	}
}
