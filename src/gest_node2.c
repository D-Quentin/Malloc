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

void init_mem(size_t size)
{
    void *ptr = sbrk(SIG_ATOMIC_MAX);

    if (ptr == (void *)-1)
        return;
    head = ptr;
    head->ptr = ptr;
    head->ptr += sizeof(list_t);
    head->free = 0;
    head->next = NULL;
    head->size = size;
    end = head;
}

list_t *new_node(size_t size)
{
    list_t *last_node = NULL;
    static int init = 0;

    if (init == 0) {
        init_mem(size);
        return (head);
    }
    if (head == NULL || end == NULL)
        return (NULL);
    last_node = end->ptr;
    last_node += end->size;
    last_node->ptr = last_node;
    last_node->ptr += sizeof(list_t);
    last_node->size = size;
    last_node->next = NULL;
    end->next = last_node;
    end = last_node;
    return (last_node);
}

list_t *find_free_node(size_t size)
{
    size_t smallest_node_size = SIZE_MAX;
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
    size_t new_size = 2;
    int i = 0;

    for (; new_size < size ; i++)
        new_size = pow(2, i);
    return (new_size);
}