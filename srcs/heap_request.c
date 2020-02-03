/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_request.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:35:51 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/03 20:57:35 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

static t_heap       *find_valid_heap(size_t data_size, t_heap *base)
{
    while (base && (base->type == TYPE_LARGE ||
            base->free_data > data_size + META_HEAP))
        base = base->next;
    return (base);
}

static t_block      *get_last_block(t_block *base)
{
    t_block     *tmp;
    
    tmp = base;
    while (tmp && tmp->next)
        tmp = tmp->next;
    return (tmp);
}

t_heap              *heap_request(t_block **last, size_t input_size)
{
    t_heap      *heap;

    *last = NULL;
    if (!(heap = find_valid_heap(input_size, get_or_update_base(NULL, FALSE))))
        heap = create_new_heap(input_size);
    else
        *last = get_last_block(heap->base);
    return (heap);
}