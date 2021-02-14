/*
** EPITECH PROJECT, 2021
** B-PSU-400-PAR-4-1-malloc-quentin.daville
** File description:
** gest_node2
*/

#include "../include/malloc2.h"
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void init_mem(size_t size, void *ptr)
{
    void *tmp_ptr = NULL;
    size_t alloc_size = getpagesize();
    int nb_page = 1;

    if (ptr == (void *)-1)
        return;
    while (alloc_size < size + sizeof(list_t)) {
        tmp_ptr = sbrk(getpagesize());
        if (tmp_ptr == (void *)-1)
            return;
        alloc_size += getpagesize();
    }
    if (nb_page % 2 == 1)
        tmp_ptr = sbrk(getpagesize());
    head = ptr;
    head->ptr = ptr + sizeof(list_t);
    head->free = 0;
    head->next = NULL;
    head->size = size;
    end = head;
}

// list_t *big_block(list_t *last_node, size_t size)
// {
//     void *ptr = sbrk(getpagesize());

//     if (ptr == (void *)-1)
//         return (NULL);
//     block_size += getpagesize();
//     if (block_size > size)
//         return (last_node);
//     return (big_block(last_node, size));
// }

// list_t *new_block(size_t size)
// {
//     void *ptr = sbrk(getpagesize());
//     list_t *last_node = NULL;

//     if (ptr == (void *)-1)
//         return (NULL);
//     last_node = ptr;
//     last_node->ptr = last_node + sizeof(list_t);
//     last_node->size = size;
//     last_node->next = NULL;
//     last_node->free = 0;
//     end->next = last_node;
//     end = last_node;
//     block_size = 0;
//     if (size >= getpagesize()) {
//         block_size = getpagesize();
//         return (big_block(last_node, size));
//     }
//     block_size += sizeof(list_t) + size;
//     return (last_node);
// }

list_t *new_node(size_t size)
{
    list_t *last_node = NULL;
    void *ptr = sbrk(getpagesize());
    int nb_page = 1;
    void *tmp_ptr = NULL;
    size_t alloc_size = getpagesize();

    if (head == NULL) {
        init_mem(size, ptr);
        return (head);
    }
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
    if (nb_page % 2 == 1)
        tmp_ptr = sbrk(getpagesize());
    last_node = ptr;
    last_node->ptr = last_node + sizeof(list_t);
    last_node->size = size;
    last_node->next = NULL;
    last_node->free = 0;
    end->next = last_node;
    end = last_node;
    return (last_node);
}

list_t *find_free_node(size_t size)
{
    size_t smallest_node_size = INT32_MAX;
    list_t *smallest_node = NULL;
    list_t *tmp = head;

    while (head != NULL) {
        if (head->free == 1 && head->size >= size &&
        head->size < smallest_node_size) {
            smallest_node_size = head->size;
            smallest_node = head;
        }
        head = head->next;
    }
    head = tmp;
    return (smallest_node);
}


list_t *go_to_node(void *ptr)
{
    if (head == NULL || ptr == NULL)
        return (NULL);
    for (list_t *tmp = head ; tmp != NULL ; tmp = tmp->next) {
        if (tmp->ptr == ptr)
            return (tmp);
    }
    return (NULL);
}

size_t pow_sup(size_t size)
{
    // size_t new_size = 2;
    // int i = 0;
    
    // size += 1000;
    // for (; new_size < size ; i++)
    //     new_size = pow(2, i);
    return (size);
}