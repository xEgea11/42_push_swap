/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_delete.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:40:25 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 14:03:49 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
    Dont forget to remove the prints
*/
/**
 * @brief Deletes (frees) the node passed as parameter
 * 
 * @param list 
 * @return int TRUE if was deleted, FALSE if it didnt succeed
 */
int	ft_dll_del_one(t_dllist *node)
{
	if (!node)
		return (FALSE);
	node->next = NULL;
	node->prev = NULL;
	free(node);
	node = NULL;
	return (TRUE);
}

/**
 * @brief Procedure to delete a node when there are 
 * 			exactly 2 elements
 * 
 * @param list 
 * @param node 
 * @return int 
 */
int	ft_del_if_2(t_dllist **list, t_dllist *node)
{
	node = ft_lastnode(*list);
	if (!node)
		return (FALSE);
	node->prev->next = NULL;
	node->prev->prev = NULL;
	if (ft_dll_del_one(node) == FALSE)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Procedure to delete a node when there are more than 
 * 			3 elems in the list
 * 
 * @param list 
 * @param node 
 * @return int 
 */
int	ft_del_if_more(t_dllist **list, t_dllist *node)
{
	node = ft_lastnode(*list);
	if (!node)
		return (FALSE);
	node->next->prev = node->prev;
	node->prev->next = node->next;
	if (ft_dll_del_one(node) == FALSE)
		return (FALSE);
	return (TRUE);
}

/**
 * @brief Deletes the last node of a list; it sets too the pointers 
 * 			so the double linked list remains stable
 * 
 * @param list 
 * @return  int     TRUE if succeeded or if list is empty, FALSE if not
 */
int	ft_dll_del_last(t_dllist **list)
{
	t_dllist	*iter;

	iter = NULL;
	if (is_empty(*list) == 1)
		return (TRUE);
	if (ft_dll_size(*list) == 1)
	{
		free(*list);
		*list = NULL;
		return (TRUE);
	}
	else if (ft_dll_size(*list) == 2)
		return (ft_del_if_2(list, iter));
	else
	{
		return (ft_del_if_more(list, iter));
	}
}

/**
 * @brief clears all the elements in the list; list is set to NULL by del_last
 * 
 * @param list 
 * @return int  TRUE if the list is fully cleared, FALSE if not
 */
int	ft_dll_clear_list(t_dllist **list)
{
	while (ft_dll_size(*list) > 0)
	{
		if (ft_dll_del_last(list) == FALSE)
			return (FALSE);
	}
	ft_dll_del_last(list);
	return (TRUE);
}
