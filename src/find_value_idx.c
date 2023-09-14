/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value_idx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 14:20:31 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/05 13:49:58 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Returns absolute value of a number
 * 
 * @param value 
 * @return long - Because we can have overflow, we return a long
 */
long	ab(int value)
{
	if (value < 0)
	{
		value *= -1;
		return (value);
	}
	else
		return (value);
}

/**
 * @brief Used to index all the nodes in the list - 
 * 			Find the max value that has no index
 * 
 * @param list The list to search
 * @return int The max value 
 */
int	ft_find_max_value(t_dllist *list)
{
	int			start;
	int			max;
	t_dllist	*itr;

	start = 0;
	max = MIN_INT;
	itr = list;
	if (!itr)
		return (0);
	while (start == 0 || itr->head != 1)
	{
		if (start == 0)
			start = 1;
		if (itr->data >= max && itr->index == -1)
			max = itr->data;
		itr = itr->next;
	}
	return (max);
}

/**
 * @brief Used to know the minimum index in a list
 * 
 * @param list 
 * @return int 
 */
int	ft_find_min_idx(t_dllist *list)
{
	int			start;
	int			min;
	t_dllist	*itr;

	start = 0;
	itr = list;
	if (!itr)
		return (0);
	min = MAX_INT;
	while (start == 0 || itr->head != 1)
	{
		if (start == 0)
			start = 1;
		if (itr->index <= min)
			min = itr->index;
		itr = itr->next;
	}
	return (min);
}

/**
 * @brief It looks for the bigges index in a list
 * 
 * @param list 
 * @return int  - The biggest value of a list
 */
int	ft_find_max_idx(t_dllist *list)
{
	int			start;
	int			max;
	t_dllist	*itr;

	start = 0;
	max = 0;
	itr = list;
	if (!itr)
		return (0);
	while (start == 0 || itr->head != 1)
	{
		if (start == 0)
			start = 1;
		if (itr->index >= max)
			max = itr->index;
		itr = itr->next;
	}
	return (max);
}
