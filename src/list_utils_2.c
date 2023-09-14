/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:56:51 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 12:26:12 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief returns the size of a list
 * 
 * @param list 
 * @return int the size of the list
 */
int	ft_dll_size(t_dllist *list)
{
	int			size;
	t_dllist	*itr;
	int			start;

	size = 0;
	start = 0;
	if (is_empty(list) == TRUE)
		return (size);
	itr = list;
	if (itr->next == NULL && itr->prev == NULL)
	{
		size = 1;
		return (size);
	}
	while (start == 0 || itr->head != 1)
	{
		if (start == 0)
			start = 1;
		itr = itr->next;
		size++;
	}
	return (size);
}

/**
 * @brief Just gets if list is Empty
 * 
 * @param list 
 * @return int  TRUE if is empty, FALSE if not
 */
int	is_empty(t_dllist *list)
{
	if (list == NULL)
		return (TRUE);
	else
		return (FALSE);
}

/**
 * @brief detects if the list is ordered
 * 
 * @param list 
 * @return int 
 */
int	ft_in_order(t_dllist *list)
{
	t_dllist	*itr;
	int			start;

	start = 0;
	if (is_empty(list) == TRUE)
		return (TRUE);
	itr = list;
	if (itr->next == NULL && itr->prev == NULL)
		return (TRUE);
	while (start == 0 || itr->head != 1)
	{
		if (start == 0)
			start = 1;
		if (itr->data > itr->next->data && itr->next->head != 1)
			return (FALSE);
		itr = itr->next;
	}
	return (TRUE);
}

/**
 * @brief Iterates a list and applies a function to each node; 
 *          made specifically to set the index into a node
 * 
 * @param l - List
 * @param f - Function
 * @param i - Index
 * @param v - Value
 */
void	ft_iter(t_dllist **l, void (*f)(t_dllist *n, int i), int i, int v)
{
	t_dllist	*iter;
	int			start;

	if (!l)
		return ;
	else
	{
		start = 0;
		iter = *l;
		while (start == 0 || iter->head != 1)
		{
			if (start == 0)
				start = 1;
			if (iter->data == v && iter->index == -1)
			{
				f(iter, i);
				return ;
			}
			iter = iter->next;
		}
	}
}
