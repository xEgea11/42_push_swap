/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:29:29 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/14 13:43:13 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Returns the number of steps that a sorted list 
 * 		has to move to insert a node - or to get to some index
 * 		0 - If the index exists, position has to be equal to index - flag 0
 * 		1 - If the index does not exist, and we want 
 * 			to insert between the max index 
 * 			and the next (it means we want to insert in the minimum index) - flag 1
 * 		2 - The index is bigger than any of the list
 * 		3 - If the index does not exist and we dont want 
 * 			to insert between the max index
 * 			(we want to insert somewhere into the list)
 * 
 * @param list The sorted list to search in
 * @param position The position where the node has to be inserted
 * @param max_idx The last node (biggest value) of the list
 * @param flag 	1 if we want to insert at the beggining of the list
 * 				0 if we want to insert somewhere else
 * @return int number of steps in a forward manner (rotate)
 */
int	ft_calculate_cost(t_dllist *list, int id, int f)
{
	int			start;
	int			cost;
	int			min_i;
	int			max_i;
	t_dllist	*itr;

	start = 0;
	cost = 0;
	itr = list;
	if (!itr)
		return (0);
	min_i = ft_find_min_idx(itr);
	max_i = ft_find_max_idx(itr);
	while (start == 0 || itr->head != 1)
	{
		if (start == 0)
			start = 1;
		if ((id < min_i && itr->prev->index == max_i && f == 1)
			|| (id > max_i && itr->index == min_i && f == 2) || id == itr->index
			|| (itr->prev->index < id && itr->index > id && f == 3))
			return (cost);
		itr = itr->next;
		cost += 1;
	}
	return (cost);
}

/**
 * @brief Calculates shortest path to go to a index, either forward or backwards
 * 
 * @param moves 
 * @param size 
 * @return int - Positive if forward, negative if backwards
 */
int	ft_path(int moves, int size)
{
	int	steps;

	steps = 0;
	if (moves > size / 2)
	{
		steps = size - moves;
		steps *= -1;
	}
	else
		steps = moves;
	return (steps);
}

/**
 * @brief Calculates the minimum steps in a to go 
 * 		  from the first node to a specified index
 * 				case 1: index is lower than the lowest one
 * 				case 2: index is higher than the highest one
 * 				case 3: index is somewhere between
 * @param a 
 * @param index 
 * @return int - Positive int if forward - Negative int if backwards
 */
int	count_steps(t_dllist *a, int index)
{
	int	size;

	size = ft_dll_size(a);
	if (index < ft_find_min_idx(a))
		return (ft_path(ft_calculate_cost(a, index, 1), size));
	else if (index > ft_find_max_idx(a))
		return (ft_path(ft_calculate_cost(a, index, 2), size));
	else
		return (ft_path(ft_calculate_cost(a, index, 3), size));
}

/**
 * @brief Calculates number of steps in a b stack to find the EXACT index
 * 
 * @param b 
 * @param index 
 * @return int 
 */
int	steps(t_dllist *b, int index)
{
	int	size;

	size = ft_dll_size(b);
	return (ft_path(ft_calculate_cost(b, index, 0), size));
}
