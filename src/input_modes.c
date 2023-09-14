/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 20:47:06 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/07 10:55:50 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}

/**
 * @brief It inserts a number into the list
 * 
 * @param list the list to receive the number
 * @param number the number to be inserted
 */
int	ft_put_number_to_list(t_dllist **list, int number)
{
	t_dllist	*node;

	node = ft_new_dll(number);
	if (!node)
		return (FALSE);
	if (is_empty(*list) == TRUE)
	{
		*list = node;
		return (TRUE);
	}
	else
	{
		if (ft_insert_back(list, node) == TRUE)
			return (TRUE);
	}
	free(node);
	return (FALSE);
}

/**
 * @brief It gets the numbers from a single array (only 1 argument);
 * 			we admit that it is always populated.
 *          Then splits the numbers, checks that every number is correct
 * 
 * @param args array of numbers candidates
 * 
 * @return the list with all the numbers
 */
t_dllist	*ft_get_arg(const char *args)
{
	t_dllist	*list;
	char		**nbs;
	int			i;

	list = NULL;
	nbs = ft_split(args, ' ');
	if (!nbs)
		return (NULL);
	i = 0;
	while (nbs[i] != NULL)
	{
		if (ft_is_int(nbs[i]) == FALSE || ft_int_range(ft_atol(nbs[i])) == FALSE
			|| ft_compare(ft_atol(nbs[i]), list) == TRUE
			|| ft_put_number_to_list(&list, (int)ft_atol(nbs[i])) == FALSE)
		{
			ft_free_matrix(nbs);
			if (list != NULL)
				ft_dll_clear_list(&list);
			write(2, "Error\n", 6);
			return (NULL);
		}
		i++;
	}
	ft_free_matrix(nbs);
	return (list);
}

/**
 * @brief Gets the numbers of the CLI if there are multiple arguments
 * 
 * @param argc 
 * @param arg 
 * @return t_dllist* 
 */
t_dllist	*ft_multiple_args(int argc, char *arg[])
{
	t_dllist	*list;
	int			i;

	i = 1;
	list = NULL;
	while (i < argc)
	{
		if (ft_is_int(arg[i]) == FALSE || ft_int_range(ft_atol(arg[i])) == FALSE
			|| ft_compare(ft_atol(arg[i]), list) == TRUE
			|| ft_put_number_to_list(&list, (int)ft_atol(arg[i])) == FALSE)
		{
			if (list != NULL)
				ft_dll_clear_list(&list);
			write(2, "Error\n", 6);
			return (NULL);
		}
		i++;
	}
	return (list);
}
