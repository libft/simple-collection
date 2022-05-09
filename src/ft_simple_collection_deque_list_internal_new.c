/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_collection_deque_list_internal_new.c     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 23:16:09 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/09 23:29:17 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_simple_collection_deque_list_internal.h"

#include <stdlib.h>

static const t_deque_list_vtable	g_v = {
	(t_deque_list_v_delete)(&ft_deque_list_v_delete),
	(t_deque_list_v_get_length)(&ft_deque_list_v_get_length),
	(t_deque_list_v_push)(&ft_deque_list_v_push_front),
	(t_deque_list_v_push)(&ft_deque_list_v_push_back),
	(t_deque_list_v_pop)(&ft_deque_list_v_pop_front),
	(t_deque_list_v_pop)(&ft_deque_list_v_pop_back),
	(t_deque_list_v_pop)(&ft_deque_list_v_peek_front),
	(t_deque_list_v_pop)(&ft_deque_list_v_peek_back),
	(t_deque_list_v_iterator)(&ft_deque_list_v_it),
	(t_deque_list_v_iterator)(&ft_deque_list_v_reverse_it),
	(t_deque_list_v_mutable_iterator)(&ft_deque_list_v_mutable_it),
	(t_deque_list_v_mutable_iterator)(&ft_deque_list_v_mutable_reverse_it),
	(t_deque_list_v_rotate)(&ft_deque_list_v_rotate_to_front),
	(t_deque_list_v_rotate)(&ft_deque_list_v_rotate_to_back),
	(t_deque_list_v_push_node)(&ft_deque_list_v_push_node_front),
	(t_deque_list_v_push_node)(&ft_deque_list_v_push_node_back),
	(t_deque_list_v_pop_node)(&ft_deque_list_v_pop_node_front),
	(t_deque_list_v_pop_node)(&ft_deque_list_v_pop_node_back),
	(t_deque_list_v_pop_node)(&ft_deque_list_v_peek_node_front),
	(t_deque_list_v_pop_node)(&ft_deque_list_v_peek_node_back),
};

t_deque_list	*new_deque_list(void (*cleaner)(void *))
{
	t_deque_list_internal *const	result = (t_deque_list_internal *)malloc(
			sizeof(t_deque_list_internal));

	if (!result)
		return (NULL);
	result->expose.v = &g_v;
	result->expose.length = 0;
	result->expose.head = NULL;
	result->expose.tail = NULL;
	result->expose.cleaner = cleaner;
	result->iterator_count = 0;
	result->mutable_iterator_count = 0;
	result->iterator = NULL;
	result->reverse_iterator = NULL;
	result->mutable_iterator = NULL;
	result->mutable_reverse_iterator = NULL;
	return ((t_deque_list *) result);
}
