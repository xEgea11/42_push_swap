/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 16:35:21 by regea-go          #+#    #+#             */
/*   Updated: 2023/09/14 13:37:19 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/include/libft.h"
# include "../libft/include/printf.h"

# define MIN_INT -2147483648
# define MAX_INT 2147483647

# define TRUE 1
# define FALSE 0

# define EXIT_SUCCESS 0
# define EXIT_FAILURE 1

typedef struct s_dllist
{
	int				data;
	int				index;
	struct s_dllist	*next;
	struct s_dllist	*prev;
	int				head;
}				t_dllist;

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	steps;
}				t_cost;

//*****Utilities for t_dllist*****

t_dllist	*ft_new_dll(int data);
int			ft_not_first_node(t_dllist *node);
int			ft_is_first_node(t_dllist *node);
int			ft_round_dllist(t_dllist **list, t_dllist *node);
t_dllist	*ft_lastnode(t_dllist *list);
int			ft_insert_back(t_dllist **list, t_dllist *node);
void		ft_set_index(t_dllist *node, int idx);
void		ft_set_all_index(t_dllist **list);

int			ft_put_number_to_list(t_dllist **list, int number);

int			ft_dll_size(t_dllist *list);
int			ft_dll_delone(t_dllist *list);
int			ft_dll_del_last(t_dllist **list);
int			ft_dll_clear_list(t_dllist **list);
int			is_empty(t_dllist *list);
void		ft_dll_print_list(t_dllist **list);
int			ft_in_order(t_dllist *list);
void		ft_iter(t_dllist **l, void (*f)(t_dllist *n, int i), int i, int v);

//*****Utilities for getting numbers from arguments*****

int			ft_is_int(const char *str);
long		ft_atol(const char *str);
int			ft_int_range(long number);
int			ft_compare(int number, t_dllist *list);
t_dllist	*ft_get_numbers(const char *arg);
void		ft_free_matrix(char **numbers);
int			ft_put_number_to_list(t_dllist **list, int number);

t_dllist	*ft_get_arg(const char *args);
t_dllist	*ft_multiple_args(int argc, char *arg[]);

//******Push_swap actions*****

/* 
	Swap actions
*/

void		ft_swap_a(t_dllist **list, int flag);
void		ft_swap_b(t_dllist **list, int flag);
void		ft_swap_a_b(t_dllist **list_a, t_dllist **list_b);

/*  
	Push actions 
*/

t_dllist	*ft_dll_pop(t_dllist **list);
void		ft_dll_push(t_dllist **list, t_dllist *node);

void		ft_dll_push_b(t_dllist **list_a, t_dllist **list_b);
void		ft_dll_push_a(t_dllist **list_b, t_dllist **list_a);

/*
	Rotate actions
*/

void		ft_dll_rotate_a(t_dllist **list, int flag);
void		ft_dll_rotate_b(t_dllist **list, int flag);
void		ft_dll_rotate_a_b(t_dllist **a, t_dllist **b);

/*
	Reverse rotate actions
*/

void		ft_dll_reverse_rotate_a(t_dllist **list, int flag);
void		ft_dll_reverse_rotate_b(t_dllist **list, int flag);
void		ft_dll_reverse_rotate_a_b(t_dllist **a, t_dllist **b);

/*
	Utilites for algorithm
*/

int			ft_find_max_value(t_dllist *list);
int			ft_find_min_idx(t_dllist *list);
int			ft_find_max_idx(t_dllist *list);
long		ab(int value);

/*
	Algorithm
*/

int			ft_calculate_cost(t_dllist *list, int id, int f);
int			count_steps(t_dllist	*a, int index);
int			steps(t_dllist *b, int index);
t_cost		*ft_combined(t_dllist *a, t_dllist *b);

void		ft_shortest_rotation_a(t_dllist **a, int cost_a);
void		ft_shortest_rotation_b(t_dllist **b, int cost_b);

int			ft_insert_in_order(t_dllist **a, t_dllist **b);
int			ft_push_swap(t_dllist **a, t_dllist **b);
void		ft_push_swap_2(t_dllist **a);
int			ft_push_swap_more(t_dllist **a, t_dllist **b, int size);

/*

	Utilites for putting the head of list at the min idx 
*/

void		ft_economic_move(t_dllist **a, int index);
void		ft_order_list(t_dllist **list);

#endif