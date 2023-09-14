/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:18:54 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 12:26:45 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Just sets the head to 0 so we know this isnt the first node
 * 
 * @param node node to be changed
 * @return int  TRUE if succeed, FALSE if not 
 */
int	ft_not_first_node(t_dllist *node)
{
	if (!node)
		return (FALSE);
	node->head = 0;
	return (TRUE);
}

/**
 * @brief Sets head to 1 if that node is the first node of the list
 * 
 * @param node 
 */
int	ft_is_first_node(t_dllist *node)
{
	if (!node)
		return (FALSE);
	node->head = 1;
	return (TRUE);
}

/**
 * @brief Gets and returns the last node of a list
 * 
 * @param list the list
 * @return t_dllist* the last node - NULL if error
 */
t_dllist	*ft_lastnode(t_dllist *list)
{
	t_dllist	*itr;

	if (is_empty(list) == TRUE)
		return (NULL);
	itr = list;
	if (itr->next == NULL && itr->prev == NULL)
		return (itr);
	while (itr->next->head != 1)
		itr = itr->next;
	return (itr);
}

/**
 * @brief Aux func to set index in function of 
 *          the theoric position into a sorted list
 * 
 * @param node 
 * @param idx 
 */
void	ft_set_index(t_dllist *node, int idx)
{
	if (!node)
		return ;
	if (idx < 0)
		return ;
	node->index = idx;
}

/**
 * @brief Sets all the indexes in a non-indexed list - It prepares the list
 * 			to be sorted
 * 
 * @param list 
 */
void	ft_set_all_index(t_dllist **list)
{
	int	max;
	int	size;

	max = 0;
	size = ft_dll_size(*list);
	while (size > 0)
	{
		max = ft_find_max_value(*list);
		ft_iter(list, ft_set_index, size, max);
		size--;
	}
}
