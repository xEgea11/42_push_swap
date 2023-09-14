/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 18:18:19 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/14 13:48:05 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Auxiliar function to print the value of every node of the list
 * 
 * @param list 
 */
void	ft_dll_print_list(t_dllist **list)
{
	t_dllist	*node;
	int			start;
	int			counter;

	if (is_empty(*list) == TRUE)
	{
		ft_printf("List is empty\n");
		return ;
	}
	node = *list;
	start = 0;
	counter = 1;
	while (node->head == 0 || start == 0)
	{
		if (start == 0)
			start = 1;
		counter++;
		if (node->next != NULL)
			node = node->next;
	}
	ft_printf("List printed successfully\n\n\n");
}
