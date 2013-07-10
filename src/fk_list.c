#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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

static list_node *new_node(void *data)
{
    list_node *ret_node = (list_node *) malloc(sizeof(list_node));
    memset(ret_node, 0, sizeof(list_node));
    ret_node->data = data;
    return ret_node;
}

bool list_is_empty(List *self)
{
    if (!self->size)
        return true;

    return false;
}

int list_size(List *self)
{
    return self->size;
}

void list_reset(List *self)
{
    self->cur = self->head;
}

void list_push_back(List *self, void *node)
{
    list_node *isrt_node = new_node(node);
    if (list_is_empty(self)) {
        self->head = isrt_node;
        self->tail = isrt_node;
    } else {
        self->tail->next = isrt_node;
        isrt_node->prev = self->tail;
        self->tail = self->tail->next;
        list_reset(self);
    }

    self->size++;
}

void list_push_front(List *self, void *node)
{
    list_node *isrt_node = new_node(node);
    if (list_is_empty(self)) {
        self->head = isrt_node;
        self->tail = isrt_node;
    } else {
        isrt_node->next = self->head;
        self->head->prev = isrt_node;
        self->head = isrt_node;
        list_reset(self);
    }

    self->size++;
}

void *list_pop_back(List *self)
{
    list_node *ret_val = self->tail;
    self->tail = self->tail->prev;
    if (self->tail) {
        void *ret_data = ret_val->data;
        free(ret_val);
        self->size--;
        list_reset(self);
        return ret_data;
    }

    return NULL;
}

void *list_pop_front(List *self)
{
    list_node *ret_val = self->head;
    self->head = self->head->next;
    if (self->head) {
        void *ret_data = ret_val->data;
        free(ret_val);
        self->size--;
        list_reset(self);
        return ret_data;
    }

    return NULL;
}

void *list_get_back(List *self)
{
    if (self->tail)
        return self->tail->data;

    return NULL;
}

void *list_get_front(List *self)
{
    if (self->head)
        return self->head->data;

    return NULL;
}

bool list_has_next(List *self)
{
    if (self->cur)
        return true;

    return false;
}

void *list_get_next(List *self)
{
    list_node *cur_node = self->cur;
    self->cur = self->cur->next;
    return cur_node->data;
}

List *new_list(void)
{
    List *ret_list = (List *) malloc(sizeof(List));
    memset(ret_list, 0, sizeof(List));
    return ret_list;
}
