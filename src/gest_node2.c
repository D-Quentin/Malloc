/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-quentin.daville
** File description:
** gest_node2
*/

#include "../include/malloc.h"
#include <stdlib.h>
#include <stdint.h>

list_t *new_node(size_t size)
{
    void *ptr = sbrk(getpagesize());
    void *tmp_ptr = NULL;
    size_t alloc_size = getpagesize();

    if (head == NULL)
        return (init_mem(size, ptr));
    if (head == NULL || end == NULL)
        return (NULL);
    if (ptr == (void *)-1)
        return (NULL);
    while (alloc_size < size + sizeof(list_t)) {
        tmp_ptr = sbrk(getpagesize());
        if (tmp_ptr == (void *)-1)
            return (NULL);
        alloc_size += getpagesize();
    }
    new_node2(size, ptr);
    return (end);
}