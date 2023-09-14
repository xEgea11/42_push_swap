/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 12:27:41 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/07 11:38:47 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Executes if there are 2 elem in the list
 * 
 * @param a 
 */
void	ft_push_swap_2(t_dllist **a)
{
	t_dllist	*node;

	node = *a;
	if (node->index < node->next->index)
		return ;
	else
	{
		ft_swap_a(a, 1);
		return ;
	}
}

/**
 * @brief Aux to execute the first case with 3 params
 * 
 * @param a 
 * @param b 
 */
static void	ft_first_case(t_dllist **a, t_dllist **b)
{
	ft_dll_push_b(a, b);
	ft_swap_a(a, 1);
	ft_dll_push_a(b, a);
}

void	ft_push_swap_3(t_dllist **a, t_dllist **b)
{
	t_dllist	*itr;

	itr = *a;
	if (ft_in_order(*a))
		return ;
	if (itr->index < itr->next->index && itr->next->index > itr->prev->index
		&& itr->prev->index > itr->index)
		ft_first_case(a, b);
	if (itr->index > itr->next->index && itr->next->index < itr->prev->index
		&& itr->prev->index > itr->index)
		ft_swap_a(a, 1);
	if (itr->index < itr->next->index && itr->next->index > itr->prev->index
		&& itr->prev->index < itr->index)
		ft_dll_reverse_rotate_a(a, 1);
	if (itr->index > itr->next->index && itr->next->index > itr->prev->index
		&& itr->prev->index < itr->index)
	{
		ft_swap_a(a, 1);
		ft_dll_reverse_rotate_a(a, 1);
	}
	if (itr->index > itr->next->index && itr->next->index < itr->prev->index
		&& itr->prev->index < itr->index)
		ft_dll_rotate_a(a, 1);
}				

int	ft_push_swap_more(t_dllist **a, t_dllist **b, int size)
{
	while (ft_dll_size(*a) > 2)
	{
		ft_dll_push_b(a, b);
		if (ft_dll_size(*b) >= 2 && (*b)->index < size / 2)
			ft_dll_rotate_b(b, 1);
	}	
	if (ft_insert_in_order(a, b) == FALSE)
	{
		ft_dll_clear_list(a);
		ft_dll_clear_list(b);
		return (FALSE);
	}
	return (TRUE);
}

/**																			
 * @brief 	When size > 3													
 * 			It pushes all the elements to be except 2
 * 			Then it pushes back in order
 * 
 * @param a 
 * @param b 
 */
int	ft_push_swap(t_dllist **a, t_dllist **b)
{
	t_dllist	*node;
	int			size;

	if (ft_dll_size(*a) <= 1)
		return (TRUE);
	size = ft_dll_size(*a);
	node = *a;
	if (ft_dll_size(*a) == 2)
	{
		ft_push_swap_2(a);
		return (TRUE);
	}
	if (ft_dll_size(*a) == 3)
	{
		ft_push_swap_3(a, b);
		return (TRUE);
	}
	return (ft_push_swap_more(a, b, size));
}
