/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:48:48 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/07 11:26:10 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
*       TODO: 
*      	- .gitignore
		- CHECK FOR LEAKS -- Its gonna be hard :(
		- Delete print_util.c once debug has done, we dont need it for the project
		- Do the full evaluation again 
*/

/**
 * @brief Main execution of push_swap
 * 
 * @param a 
 * @param b 
 * @return int - return code 
 */
static int	ft_main_exec(t_dllist **a, t_dllist **b)
{
	if (ft_in_order(*a) == TRUE)
	{
		ft_dll_clear_list(a);
		ft_dll_clear_list(b);
		return (EXIT_SUCCESS);
	}
	ft_set_all_index(a);
	if (ft_push_swap(a, b) == FALSE)
	{
		ft_dll_clear_list(a);
		ft_dll_clear_list(b);
		return (EXIT_FAILURE);
	}
	ft_dll_clear_list(a);
	ft_dll_clear_list(b);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_dllist	*a;
	t_dllist	*b;
	int			size;

	size = 0;
	a = NULL;
	b = NULL;
	if (argc < 2)
		return (EXIT_FAILURE);
	else if (argc == 2)
	{
		a = ft_get_arg(argv[1]);
		if (ft_dll_size(a) == 1)
		{
			ft_dll_clear_list(&a);
			return (EXIT_SUCCESS);
		}
	}
	else if (argc > 2)
		a = ft_multiple_args(argc, argv);
	return (ft_main_exec(&a, &b));
}
