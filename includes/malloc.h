/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:14:57 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/03 20:55:02 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MALLOC_H
# define MALLOC_H

/*
**      - > INCLUDES
*/
#include <stdio.h>

/*
**      - > STRUCTS
*/
typedef struct          s_block
{
    struct s_block      *next;
    size_t              size;
    char                freed;
}                       t_block;

typedef struct          s_heap
{
    char                type;
    struct s_heap       *next;
    size_t              free_data;
    t_block             *base;
}                       t_heap;

/*
**      - > DEFINES
*/
#define NONE            0
#define FREED           1
#define FALSE           0
#define TRUE            1
#define META_HEAP       sizeof(t_heap)
#define META_BLOCK      sizeof(t_block)
#define TYPE_SMALL      0
#define TYPE_TYNY       1
#define TYPE_LARGE      2

/*
**      - > GLOBAL BASE
*/
extern  void            *g_base;

/*
**      - > METHOD PROTO
*/
void                    *malloc(size_t size);

t_heap                  *heap_request(t_block **last, size_t imput_size);
t_block                 *request_allocation(t_heap *heap, t_block *last, size_t data_size);
t_block                 *request_allocation(t_heap *heap, t_block *last, size_t data_size);
void                    *get_or_update_base(void *new_base, char get_or_uptdate);
t_heap                  *create_new_heap(size_t data_size);

#endif
