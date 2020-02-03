/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_new_heap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:01:21 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/03 20:51:56 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <sys/mman.h>
#include <unistd.h>

static void     append_heap(t_heap *new_heap)
{
    t_heap      *last_base;

    last_base = get_or_update_base(NULL, FALSE);
    while (last_base && last_base->next)
        last_base = last_base->next;
    if (!last_base)
        get_or_update_base(new_heap, TRUE);
    else
        last_base->next = new_heap;
}

static void     get_heap_fill(size_t *heap_size, char **heap_type, size_t **free_data,
                    size_t page_size)
{
    *heap_size = page_size;
    **heap_type = TYPE_TYNY;
    **free_data = *heap_size - META_BLOCK; 
}

static size_t   get_heap_size(size_t data_size, char *heap_type, size_t *free_data)
{
    size_t      page_size;
    size_t      total;
    size_t      heap_size;

    page_size = (size_t)getpagesize();
    total = data_size + META_HEAP;
    if (total > 2 * page_size)
    {
        heap_size = page_size + page_size * (total / page_size);
        *heap_type = TYPE_LARGE;
        *free_data = heap_size - META_HEAP;
    }
    else if (total > page_size)
    {
        heap_size = 2 * page_size;
        *heap_type = TYPE_SMALL;
        *free_data = heap_size - META_HEAP;
    }
    else
        get_heap_fill(&heap_size, &heap_type, &free_data, page_size);
    return (heap_size);
}          

t_heap          *create_new_heap(size_t data_size)
{
    t_heap      *new_heap;
    size_t      free_data;
    size_t      size;
    char        heap_type;

    size = get_heap_size(data_size, &heap_type, &free_data);
    if (!(new_heap = mmap(0, size,
            PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
        return (NULL);
    new_heap->type = heap_type;
    new_heap->next = NULL;
    new_heap->free_data = free_data;
    new_heap->base = NULL;
    append_heap(new_heap);
    return (new_heap);
}