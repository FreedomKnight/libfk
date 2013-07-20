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
bool list_insert(List *self, int index, void *node);
bool list_delete(List *self, int index);
void list_push_back(List *self, void *node);
void list_push_front(List *self, void *node);
void *list_pop_back(List *self);
void *list_pop_front(List *self);
void *list_get_back(List *self);
void *list_get_front(List *self);
bool list_has_cur(List *self);
void *list_get_cur(List *self);
bool list_delete_cur(List *self);
bool list_has_next(List *self);
void *list_get_next(List *self);
void list_move_next(List *self);
bool list_has_prev(List *self);
void *list_get_prev(List *self);
void list_move_prev(List *self);
List *new_list(void);
void delete_list(List *self);
#endif
