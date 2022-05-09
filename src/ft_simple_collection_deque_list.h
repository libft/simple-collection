/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_collection_deque_list.h                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:06:30 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/09 23:19:07 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_COLLECTION_DEQUE_LIST_H
# define FT_SIMPLE_COLLECTION_DEQUE_LIST_H

# include "ft_simple_collection_deque.h"

typedef struct s_deque_list_node
{
	struct s_deque_list_node	*next;
	struct s_deque_list_node	*prev;
	void						*value;
}	t_deque_list_node;

typedef struct s_deque_list
{
	const struct s_deque_list_vtable	*v;
	size_t								length;
	t_deque_list_node					*head;
	t_deque_list_node					*tail;
	void								(*cleaner)(void *);
}	t_deque_list;

typedef struct s_deque_list_iterator
{
	const struct s_deque_list_iterator_vtable	*v;
	t_deque_list_node							*node;
}	t_deque_list_iterator;

typedef struct s_deque_list_mutable_iterator
{
	const struct s_deque_list_mutable_iterator_vtable	*v;
	t_deque_list_node									*node;
}	t_deque_list_mutable_iterator;

typedef void	(*t_deque_list_iterator_v_delete)(
					t_deque_list_iterator *self);
typedef bool	(*t_deque_list_iterator_v_check)(
					t_deque_list_iterator *self);
typedef bool	(*t_deque_list_iterator_v_get)(
					t_deque_list_iterator *self,
					void **out);
typedef bool	(*t_deque_list_iterator_v_get_current_node)(
					t_deque_list_iterator *self,
					t_deque_list_node **out);
typedef bool	(*t_deque_list_iterator_v_get_node)(
					t_deque_list_iterator *self,
					t_deque_list_node **out);

typedef void	(*t_deque_list_mutable_iterator_v_delete)(
					t_deque_list_mutable_iterator *self);
typedef bool	(*t_deque_list_mutable_iterator_v_check)(
					t_deque_list_mutable_iterator *self);
typedef bool	(*t_deque_list_mutable_iterator_v_get)(
					t_deque_list_mutable_iterator *self,
					void **out);
typedef bool	(*t_deque_list_mutable_iterator_v_set)(
					t_deque_list_mutable_iterator *self,
					void *value);
typedef bool	(*t_deque_list_mutable_iterator_v_get_node)(
					t_deque_list_mutable_iterator *self,
					t_deque_list_node **out);
typedef bool	(*t_deque_list_mutable_iterator_v_set)(
					t_deque_list_mutable_iterator *self,
					void *value);
typedef bool	(*t_deque_list_mutable_iterator_v_set_node)(
					t_deque_list_mutable_iterator *self,
					t_deque_list_node *node);

typedef struct s_deque_list_const_iterator_vtable
{
	t_deque_list_iterator_v_delete		free;
	t_deque_list_iterator_v_check		has_next;
	t_deque_list_iterator_v_get			next;
	t_deque_list_iterator_v_check		is_valid;
	t_deque_list_iterator_v_get			current;
	t_deque_list_iterator_v_get_node	next_node;
	t_deque_list_iterator_v_get_node	current_node;
}	t_deque_list_const_iterator_vtable;

typedef struct s_deque_list_iterator_vtable
{
	t_deque_list_mutable_iterator_v_delete		free;
	t_deque_list_mutable_iterator_v_check		has_next;
	t_deque_list_mutable_iterator_v_get			next;
	t_deque_list_mutable_iterator_v_check		is_valid;
	t_deque_list_mutable_iterator_v_get			current;
	t_deque_list_mutable_iterator_v_set			set_current;
	t_deque_list_mutable_iterator_v_get_node	next_node;
	t_deque_list_mutable_iterator_v_get_node	current_node;
	t_deque_list_mutable_iterator_v_get_node	pop_node;
	t_deque_list_mutable_iterator_v_set			insert_before;
	t_deque_list_mutable_iterator_v_set			insert_after;
	t_deque_list_mutable_iterator_v_set_node	insert_node_before;
	t_deque_list_mutable_iterator_v_set_node	insert_node_after;
	t_deque_list_mutable_iterator_v_check		remove_current;
}	t_deque_list_mutable_iterator_vtable;

typedef void	(*t_deque_list_v_delete)(
					t_deque_list *self);
typedef size_t	(*t_deque_list_v_get_length)(
					t_deque_list *self);
typedef bool	(*t_deque_list_v_push)(
					t_deque_list *self,
					void *value);
typedef bool	(*t_deque_list_v_pop)(
					t_deque_list *self,
					void **out);
typedef bool	(*t_deque_list_v_iterator)(
					t_deque_list *self,
					t_deque_list_iterator **out);
typedef bool	(*t_deque_list_v_mutable_iterator)(
					t_deque_list *self,
					t_deque_list_mutable_iterator **out);
typedef bool	(*t_deque_list_v_rotate)(
					t_deque_list *self);
typedef bool	(*t_deque_list_v_push_node)(
					t_deque_list *self,
					t_deque_list_node *node);
typedef bool	(*t_deque_list_v_pop_node)(
					t_deque_list *self,
					t_deque_list_node **out);

typedef struct s_deque_list_vtable
{
	t_deque_list_v_delete			free;
	t_deque_list_v_get_length		get_length;
	t_deque_list_v_push				push_front;
	t_deque_list_v_push				push_back;
	t_deque_list_v_pop				pop_front;
	t_deque_list_v_pop				pop_top;
	t_deque_list_v_pop				peek_front;
	t_deque_list_v_pop				peek_top;
	t_deque_list_v_iterator			iterator;
	t_deque_list_v_iterator			reverse_iterator;
	t_deque_list_v_mutable_iterator	mutable_iterator;
	t_deque_list_v_mutable_iterator	mutable_reverse_iterator;
	t_deque_list_v_rotate			rotate_to_front;
	t_deque_list_v_rotate			rotate_to_back;
	t_deque_list_v_push_node		push_node_front;
	t_deque_list_v_push_node		push_node_back;
	t_deque_list_v_pop_node			pop_node_front;
	t_deque_list_v_pop_node			pop_node_back;
	t_deque_list_v_pop_node			peek_node_front;
	t_deque_list_v_pop_node			peek_node_back;
}	t_deque_list_vtable;

t_deque_list	*new_deque_list(void (*cleaner)(void *));

#endif
