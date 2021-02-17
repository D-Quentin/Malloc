/*
** EPITECH PROJECT, 2021
** Test_my_malloc
** File description:
** gest_node
*/

#include "../include/malloc.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

list_t *init_mem(size_t size, void *ptr)
{
    size_t alloc_size = getpagesize();

    while (alloc_size < size + sizeof(list_t)) {
        if (sbrk(getpagesize()) == (void *)-1)
            return (NULL);
        alloc_size += getpagesize();
    }
    if (sbrk(getpagesize()) == (void *)-1)
        return (NULL);
    head = ptr;
    head->ptr = ptr + sizeof(list_t);
    head->free = 0;
    head->next = NULL;
    head->size = size;
    end = head;
    return (head);
}

list_t *new_node(size_t size)
{
    void *ptr = sbrk(getpagesize());
    size_t alloc_size = getpagesize();

    if (head == NULL)
        return (init_mem(size, ptr));
    if (head == NULL || end == NULL || ptr == (void *)-1)
        return (NULL);
    while (alloc_size < size + sizeof(list_t)) {
        if (sbrk(getpagesize()) == (void *)-1)
            return (NULL);
        alloc_size += getpagesize();
    }
    new_node2(size, ptr);
    return (end);
}

void new_node2(size_t size, void *ptr)
{
    list_t *last_node = NULL;

    if (sbrk(getpagesize()) == (void *)-1)
        return;
    last_node = ptr;
    last_node->ptr = last_node + sizeof(list_t);
    last_node->size = size;
    last_node->next = NULL;
    last_node->free = 0;
    end->next = last_node;
    end = last_node;
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