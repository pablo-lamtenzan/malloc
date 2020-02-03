/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plamtenz <plamtenz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 20:48:35 by plamtenz          #+#    #+#             */
/*   Updated: 2020/02/03 21:16:55 by plamtenz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include <stdio.h>

int main()
{
    char *test;

    test = malloc(sizeof(char) * 9);
    int *test2 = malloc(sizeof(int));
    printf("%p %p" , (void *)test, test2);
    
}