/*
** EPITECH PROJECT, 2021
** Test_my_malloc
** File description:
** my_malloc
*/

#include "../include/malloc2.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void *malloc(size_t size)
{
    // if (my_ptr == NULL)
    //     my_ptr = sbrk(SIG_ATOMIC_MAX);
    // if (my_ptr == (void *)-1)
    //     exit(84);
    // if (my_ptr == NULL)
    //     exit(84);
    // my_ptr += nbr_prt;
    // nbr_prt += size;
    // return (my_ptr);
    size_t real_size = pow_sup(size);
    list_t *node = find_free_node(real_size);

    if (size == 0)
        return (NULL);
    if (node == NULL)
        node = new_node(real_size);
    if (node == NULL)
        return (NULL);
    return (node->ptr);
}

void free(void *ptr)
{
    list_t *node = go_to_node(ptr);

    if (node == NULL)
        return;
    memset(ptr, 0, node->size);
    node->free = 1;
}

void *realloc(void *ptr, size_t size)
{
    void *new_ptr = NULL;
    list_t *node = go_to_node(ptr);

    if (ptr == NULL)
        return (malloc(size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (node == NULL)
        return (NULL);
    if (size <= node->size)
        return (ptr);
    new_ptr = malloc(size);
    if (new_ptr == NULL)
        return (NULL);
    memcpy(new_ptr, ptr, size - 1);
    free(ptr);
    return (new_ptr);
    // if (node != NULL && real_size <= node->size) {
    //     node->size = real_size;
    //     return (node->ptr);
    // }
    // if (node != NULL) {
    //     tmp = malloc(real_size);
    //     memcpy(tmp, ptr, real_size - 1);
    //     free(ptr);
    //     return (tmp);
    // }
    // return (NULL);
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(nmemb * size);

    if (ptr == NULL)
        return (NULL);
    memset(ptr, 0, nmemb * size);
    return (ptr);
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
    void *new_ptr = NULL;
    list_t *node = go_to_node(ptr);

    if (ptr == NULL)
        return (calloc(nmemb, size));
    if (size == 0) {
        free(ptr);
        return (NULL);
    }
    if (node == NULL)
        return (NULL);
    if (size <= node->size)
        return (ptr);
    new_ptr = calloc(nmemb, size);
    if (new_ptr == NULL)
        return (NULL);
    memcpy(new_ptr, ptr, size - 1);
    free(ptr);
    return (new_ptr);
}