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
    void *tmp_ptr = NULL;
    size_t alloc_size = getpagesize();

    if (ptr == (void *)-1)
        return (NULL);
    while (alloc_size < size + sizeof(list_t)) {
        tmp_ptr = sbrk(getpagesize());
        if (tmp_ptr == (void *)-1)
            return (NULL);
        alloc_size += getpagesize();
    }
    init_mem2(size, ptr);
    return (head);
}

void init_mem2(size_t size, void *ptr)
{
    void *tmp_ptr = sbrk(getpagesize());
    if (tmp_ptr == (void *)-1)
        return;
    head = ptr;
    head->ptr = ptr + sizeof(list_t);
    head->free = 0;
    head->next = NULL;
    head->size = size;
    end = head;
}

void new_node2(size_t size, void *ptr)
{
    list_t *last_node = NULL;
    void *tmp_ptr = sbrk(getpagesize());

    if (tmp_ptr == (void *)-1)
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