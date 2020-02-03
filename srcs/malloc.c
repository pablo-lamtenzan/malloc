/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:37:07 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/03 21:36:06 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void        *malloc(size_t size)
{
    t_block     *block;
    t_block     *last;
    t_heap      *heap;
    
    block = NULL;
    if (size <= 0 ||
    !((heap = heap_request(&last, size)) &&
    (block = request_allocation(heap, last, size))))
        return (NULL);
    return ((void *)block + 1);
}

/* 1st verify if we have a heap right now, if we dont have we gen one, in our heap we gonna 
    check if a data block have less size to be appended to the heap 
    (muy resumido xD, nos vemos en 5 meses cuando lo corrija) */

/* for free() :

    void *free(void *ptr)
    {
        void *total;

        //address to free - metadata size

        total = prt - sizeof(t_heap) // who cares just sizeof an struct (32 bits)

        nummap(total, * (size_t*) total 

        // have to solve fragmentation problem too
    }