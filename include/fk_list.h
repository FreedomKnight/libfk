#ifndef FK_LIST_H
#define FK_LIST_H
#include <stdlib.h>
#include <stdbool.h>
typedef struct list_node {
    void *data;
    struct list_node *prev;
    struct list_node *next;
} list_node;

typedef struct List {
    list_node *head;
    list_node *cur;
    list_node *tail;
    size_t size;
} List;

bool list_is_empty(List *self);
int list_size(List *self);
void list_reset(List *self);
void list_push_back(List *self, void *node);
void list_push_front(List *self, void *node);
void *list_pop_back(List *self);
void *list_pop_front(List *self);
void *list_get_back(List *self);
void *list_get_front(List *self);
bool list_has_next(List *self);
void *list_get_next(List *self);
List *new_list(void);
#endif
