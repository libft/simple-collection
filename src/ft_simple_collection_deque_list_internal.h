/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_collection_deque_list_internal.h         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:06:30 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/09 23:29:08 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_COLLECTION_DEQUE_LIST_INTERNAL_H
# define FT_SIMPLE_COLLECTION_DEQUE_LIST_INTERNAL_H

# include "ft_simple_collection_deque_list.h"

typedef struct s_deque_list_iterator_node
{
	struct s_deque_list_iterator_node	*next;
	struct s_deque_list_iterator		*self;
}	t_deque_list_iterator_node;

typedef struct s_deque_list_mutable_iterator_node
{
	struct s_deque_list_mutable_iterator_node	*next;
	struct s_deque_list_mutable_iterator		*self;
}	t_deque_list_mutable_iterator_node;

typedef struct s_deque_list_internal
{
	t_deque_list						expose;
	size_t								iterator_count;
	size_t								mutable_iterator_count;
	t_deque_list_iterator_node			*iterator;
	t_deque_list_iterator_node			*reverse_iterator;
	t_deque_list_mutable_iterator_node	*mutable_iterator;
	t_deque_list_mutable_iterator_node	*mutable_reverse_iterator;
}	t_deque_list_internal;

typedef struct s_deque_list_iterator_internal
{
	t_deque_list_iterator	expose;
	t_deque_list_internal	*origin;
}	t_deque_list_iterator_internal;

typedef struct s_deque_list_mutable_iterator_internal
{
	t_deque_list_mutable_iterator	expose;
	t_deque_list_internal			*origin;
}	t_deque_list_mutable_iterator_internal;

void	ft_deque_list_v_delete(
			t_deque_list_internal *self);
size_t	ft_deque_list_v_get_length(
			t_deque_list_internal *self);
bool	ft_deque_list_v_push_front(
			t_deque_list_internal *self,
			void *value);
bool	ft_deque_list_v_push_back(
			t_deque_list_internal *self,
			void *value);
bool	ft_deque_list_v_pop_front(
			t_deque_list_internal *self,
			void **out);
bool	ft_deque_list_v_pop_back(
			t_deque_list_internal *self,
			void **out);
bool	ft_deque_list_v_peek_front(
			t_deque_list_internal *self,
			void **out);
bool	ft_deque_list_v_peek_back(
			t_deque_list_internal *self,
			void **out);
bool	ft_deque_list_v_it(
			t_deque_list_internal *self,
			t_deque_list_iterator **out);
bool	ft_deque_list_v_reverse_it(
			t_deque_list_internal *self,
			t_deque_list_iterator **out);
bool	ft_deque_list_v_mutable_it(
			t_deque_list_internal *self,
			t_deque_list_mutable_iterator **out);
bool	ft_deque_list_v_mutable_reverse_it(
			t_deque_list_internal *self,
			t_deque_list_mutable_iterator **out);
bool	ft_deque_list_v_rotate_to_front(
			t_deque_list_internal *self);
bool	ft_deque_list_v_rotate_to_back(
			t_deque_list_internal *self);
bool	ft_deque_list_v_push_node_front(
			t_deque_list_internal *self,
			t_deque_list_node *value);
bool	ft_deque_list_v_push_node_back(
			t_deque_list_internal *self,
			t_deque_list_node *value);
bool	ft_deque_list_v_pop_node_front(
			t_deque_list_internal *self,
			t_deque_list_node **out);
bool	ft_deque_list_v_pop_node_back(
			t_deque_list_internal *self,
			t_deque_list_node **out);
bool	ft_deque_list_v_peek_node_front(
			t_deque_list_internal *self,
			t_deque_list_node **out);
bool	ft_deque_list_v_peek_node_back(
			t_deque_list_internal *self,
			t_deque_list_node **out);

void	ft_deque_list_iterator_v_free(
			t_deque_list_iterator *self);

bool	ft_deque_list_iterator_v_has_next(
			t_deque_list_iterator *self);
bool	ft_deque_list_iterator_v_next(
			t_deque_list_iterator *self,
			void **out);
bool	ft_deque_list_iterator_v_is_valid(
			t_deque_list_iterator *self);
bool	ft_deque_list_iterator_v_current(
			t_deque_list_iterator *self,
			void **out);
bool	ft_deque_list_iterator_v_next_node(
			t_deque_list_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_iterator_v_current_node(
			t_deque_list_iterator *self,
			t_deque_list_node **out);

bool	ft_deque_list_reverse_iterator_v_has_next(
			t_deque_list_iterator *self);
bool	ft_deque_list_reverse_iterator_v_next(
			t_deque_list_iterator *self,
			void **out);
bool	ft_deque_list_reverse_iterator_v_is_valid(
			t_deque_list_iterator *self);
bool	ft_deque_list_reverse_iterator_v_current(
			t_deque_list_iterator *self,
			void **out);
bool	ft_deque_list_reverse_iterator_v_next_node(
			t_deque_list_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_reverse_iterator_v_current_node(
			t_deque_list_iterator *self,
			t_deque_list_node **out);

void	ft_deque_list_mutable_iterator_v_free(
			t_deque_list_mutable_iterator *self);

bool	ft_deque_list_mutable_iterator_v_has_next(
			t_deque_list_mutable_iterator *self);
bool	ft_deque_list_mutable_iterator_v_next(
			t_deque_list_mutable_iterator *self,
			void **out);
bool	ft_deque_list_mutable_iterator_v_is_valid(
			t_deque_list_mutable_iterator *self);
bool	ft_deque_list_mutable_iterator_v_current(
			t_deque_list_mutable_iterator *self,
			void **out);
bool	ft_deque_list_mutable_iterator_v_set_current(
			t_deque_list_mutable_iterator *self,
			void *value);
bool	ft_deque_list_mutable_iterator_v_next_node(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_mutable_iterator_v_current_node(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_mutable_iterator_v_pop_node(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_mutable_iterator_v_insert_before(
			t_deque_list_mutable_iterator *self,
			void *value);
bool	ft_deque_list_mutable_iterator_v_insert_after(
			t_deque_list_mutable_iterator *self,
			void *value);
bool	ft_deque_list_mutable_iterator_v_insert_node_before(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node *node);
bool	ft_deque_list_mutable_iterator_v_insert_node_after(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node *node);
bool	ft_deque_list_mutable_iterator_v_remove_current(
			t_deque_list_mutable_iterator *self);

bool	ft_deque_list_mutable_reverse_iterator_v_has_next(
			t_deque_list_mutable_iterator *self);
bool	ft_deque_list_mutable_reverse_iterator_v_next(
			t_deque_list_mutable_iterator *self,
			void **out);
bool	ft_deque_list_mutable_reverse_iterator_v_is_valid(
			t_deque_list_mutable_iterator *self);
bool	ft_deque_list_mutable_reverse_iterator_v_current(
			t_deque_list_mutable_iterator *self,
			void **out);
bool	ft_deque_list_mutable_reverse_iterator_v_set_current(
			t_deque_list_mutable_iterator *self,
			void *value);
bool	ft_deque_list_mutable_reverse_iterator_v_next_node(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_mutable_reverse_iterator_v_current_node(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_mutable_reverse_iterator_v_pop_node(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node **out);
bool	ft_deque_list_mutable_reverse_iterator_v_insert_before(
			t_deque_list_mutable_iterator *self,
			void *value);
bool	ft_deque_list_mutable_reverse_iterator_v_insert_after(
			t_deque_list_mutable_iterator *self,
			void *value);
bool	ft_deque_list_mutable_reverse_iterator_v_insert_node_before(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node *node);
bool	ft_deque_list_mutable_reverse_iterator_v_insert_node_after(
			t_deque_list_mutable_iterator *self,
			t_deque_list_node *node);
bool	ft_deque_list_mutable_reverse_iterator_v_remove_current(
			t_deque_list_mutable_iterator *self);

#endif
