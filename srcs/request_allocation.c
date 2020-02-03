/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   request_allocation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:24:05 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/03 16:44:40 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <sys/mman.h>

t_block         *request_allocation(t_heap *heap, t_block *last, size_t data_size)
{
    t_block     *allocation;
    if (!(allocation = mmap(0, data_size + META_BLOCK,
            PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
        return (NULL);
    if (!last)
        heap->base = allocation;
    else
        last->next = allocation;
    allocation->next = NULL;
    allocation->size = data_size;
    allocation->freed = NONE;
    if (heap->type != TYPE_LARGE)
        heap->free_data -= data_size + META_BLOCK;
    return (allocation);
}