/*
** EPITECH PROJECT, 2021
** Test_my_malloc
** File description:
** gest_node
*/

#include "../include/malloc.h"
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

list_t *create_node(void)
{
    void *ptr = sbrk(sizeof(list_t) + 1);
    list_t *prev = NULL;

    if (ptr == (void *)-1)
        return (NULL);
    while (list != NULL) {
        prev = list;
        list = list->next;
    }
    list = ptr;
    list->next = NULL;
    list->prev = prev;
    list->free = 0;
    return (list);
}

list_t *new_node(size_t size)
{
    void *ptr;
    list_t *last_node = create_node();

    go_to_first();
    if (last_node == NULL)
        return (NULL);
    ptr = sbrk(size + 1);
    if (ptr == (void *)-1)
        return (NULL);
    last_node->ptr = ptr;
    last_node->size = size;
    go_to_first();
    return (last_node);
}

list_t *find_free_node(size_t size)
{
    size_t smallest_node_size = SIZE_MAX;
    list_t *smallest_node = NULL;

    while (list != NULL) {
        if (list->free == 1 && list->size >= size &&
        list->size < smallest_node_size) {
            smallest_node_size = list->size;
            smallest_node = list;
        }
        list = list->next;
    }
    go_to_first();
    return (smallest_node);
}

void go_to_first(void)
{
    if (list == NULL)
        return;
    while (list->prev != NULL)
        list = list->prev;
}

list_t *go_to_node(void *ptr)
{
    if (list == NULL || ptr == NULL)
        return (NULL);
    for (list_t *tmp = list ; tmp != NULL ; tmp = tmp->next) {
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