/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:46:36 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/04 10:54:27 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Frees all the memory of matrix when something goes wrong 
 * 
 * @param numbers Matrix with numbers in char * format
 */
void	ft_free_matrix(char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		free(numbers[i]);
		numbers[i] = NULL;
		i++;
	}
	free(numbers);
}

/**					<-----Declare int as size_t??
 * @brief Checks if the string has letters or points (is not an int)
 * 
 * @param str number string that may contain letters or other characters
 * @return int 1 (TRUE) if it is an integer or 0 (FALSE) if its not
 */
int	ft_is_int(const char *str)
{
	size_t	i;

	if (!str || ft_strncmp(str, "", 1) == 0)
		return (FALSE);
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == FALSE && str[i] != '-')
			return (FALSE);
		i++;
	}
	return (TRUE);
}

/**
 * @brief Changes from string to int; it doesnt check if 
 * 			its not in the range of the ints
 * 
 * @param str number in string format
 * @return int number in int format (maybe it is a long)
 */
long	ft_atol(const char *str)
{
	int		sign;
	long	value;
	int		i;

	sign = 1;
	value = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45)
	{
		sign = -1;
		i++;
	}
	else if (str[i] == 43)
	{
		sign = 1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		value = value * 10 + str[i++] - '0';
	value = value * sign;
	return (value);
}

/**
 * @brief it returns true or false depending the range of the number
 * 
 * @param a possibly long number
 * 
 * @return int  1 (TRUE) if it is an integer number; 0 (FALSE) if it is not
 */
int	ft_int_range(long number)
{
	if (number > MAX_INT || number < MIN_INT)
		return (FALSE);
	else
		return (TRUE);
}

/**
 * @brief Iterates a list and checks if 
 * 			a number is already present into that list
 * 
 * @param number a number that will be compared to
 * @param list the list containing all the numbers
 * @return int 1 (TRUE) if it is already into the list; 0 (FALSE) if it is not
 */
int	ft_compare(int number, t_dllist *list)
{
	t_dllist	*iter;
	int			start;

	if (is_empty(list) == TRUE)
		return (FALSE);
	else
	{
		start = 0;
		iter = list;
		while (iter->head == 0 || start == 0)
		{
			if (start == 0)
				start = 1;
			if (iter->data == number)
				return (TRUE);
			if (iter->next != NULL)
				iter = iter->next;
		}
		return (FALSE);
	}
}
