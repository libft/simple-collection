/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_collection_deque.h                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaing <jmaing@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:28:07 by jmaing            #+#    #+#             */
/*   Updated: 2022/05/07 22:24:51 by jmaing           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SIMPLE_COLLECTION_DEQUE_H
# define FT_SIMPLE_COLLECTION_DEQUE_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_deque
{
	const struct s_deque_vtable	*v;
}	t_deque;

typedef struct s_deque_const_iterator
{
	const struct s_deque_const_iterator_vtable	*v;
}	t_deque_const_iterator;

typedef struct s_deque_iterator
{
	const struct s_deque_iterator_vtable	*v;
}	t_deque_iterator;

typedef void	(*t_deque_const_iterator_v_delete)(
					t_deque_const_iterator *self);
typedef bool	(*t_deque_const_iterator_v_has_next)(
					t_deque_const_iterator *self);
typedef bool	(*t_deque_const_iterator_v_get_next)(
					t_deque_const_iterator *self,
					void **out);

typedef void	(*t_deque_iterator_v_delete)(
					t_deque_iterator *self);
typedef bool	(*t_deque_iterator_v_has_next)(
					t_deque_iterator *self);
typedef bool	(*t_deque_iterator_v_get_next)(
					t_deque_iterator *self,
					void **out);
typedef bool	(*t_deque_iterator_v_set_current)(
					t_deque_iterator *self,
					void **out);
typedef bool	(*t_deque_iterator_v_remove_current)(
					t_deque_iterator *self,
					void **out);

typedef struct s_deque_const_iterator_vtable
{
	t_deque_const_iterator_v_delete		free;
	t_deque_const_iterator_v_has_next	has_next;
	t_deque_const_iterator_v_get_next	get_next;
}	t_deque_const_iterator_vtable;

typedef struct s_deque_iterator_vtable
{
	t_deque_iterator_v_delete	free;
	t_deque_iterator_v_has_next	has_next;
	t_deque_iterator_v_get_next	get_next;
}	t_deque_iterator_vtable;

typedef void	(*t_deque_v_delete)(t_deque *self);
typedef size_t	(*t_deque_v_get_length)(
					t_deque *self);
typedef bool	(*t_deque_v_push)(
					t_deque *self,
					void *value);
typedef bool	(*t_deque_v_pop)(
					t_deque *self,
					void **out);
typedef bool	(*t_deque_v_peek)(
					t_deque *self,
					void **out);
typedef bool	(*t_deque_v_iterator)(
					t_deque *self,
					t_deque_iterator **out);
typedef bool	(*t_deque_v_const_iterator)(
					t_deque *self,
					t_deque_const_iterator **out);

typedef struct s_deque_vtable
{
	t_deque_v_delete			free;
	t_deque_v_get_length		get_length;
	t_deque_v_push				push_front;
	t_deque_v_push				push_back;
	t_deque_v_pop				pop_front;
	t_deque_v_pop				pop_top;
	t_deque_v_peek				peek_front;
	t_deque_v_peek				peek_top;
	t_deque_v_iterator			iterator;
	t_deque_v_iterator			reverse_iterator;
	t_deque_v_const_iterator	const_iterator;
	t_deque_v_const_iterator	const_reverse_iterator;
}	t_deque_vtable;

#endif
