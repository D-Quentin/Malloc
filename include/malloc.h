/*
** EPITECH PROJECT, 2021
** Test_my_malloc
** File description:
** my_malloc
*/

#ifndef MY_MALLOC_H_
#define MY_MALLOC_H_

#include <unistd.h>

typedef struct list_s list_t;
struct list_s
{
    list_t *next;
    int free;
    void *ptr;
    size_t size;
};

static list_t *head = NULL;
static list_t *end = NULL;

// Gest node
list_t *new_node(size_t size);
void new_node2(size_t size, void *ptr);
list_t *find_free_node(size_t size);
list_t *go_to_node(void *ptr);
list_t *init_mem(size_t size, void *ptr);

//Alloc
void free(void *ptr);
void *malloc(size_t size);
void *realloc(void *ptr, size_t size);
void *calloc(size_t nmemb, size_t size);
void *reallocarray(void *ptr, size_t nmemb, size_t size);

#endif /* !MY_MALLOC_H_ */
