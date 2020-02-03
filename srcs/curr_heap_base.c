/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curr_heap_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 16:53:53 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/03 20:54:55 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

void *g_base = NULL;

void        *get_or_update_base(void *new_base, char get_or_update)
{
    if (get_or_update)
    {
        g_base = new_base;
        return (NULL);
    }
    else
        return (g_base);
}        