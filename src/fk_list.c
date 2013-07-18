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
    if (self && !self->size)
        return true;

    return false;
}

int list_size(List *self)
{
    if (self)
        return self->size;

    return 0;
}

void list_reset(List *self)
{
    if (self)
        self->cur = self->head;
}

bool list_insert(List *self, int index, void *node)
{
    if (self && index <= list_size(self) && index >= 0) {
        list_node *isrt_node = new_node(node);
        int i = 0;
        list_node *cur = self->head;
        while (!list_is_empty(self) && i != index) {
            cur = cur -> next;
            i++;
        }

        if (list_is_empty(self)) {
            self->head = isrt_node;
            self->tail = isrt_node;
        } else {
            isrt_node->next = cur;
            if (cur) {
                isrt_node->prev = cur->prev;
            } else {
                self->tail->next = isrt_node;
                isrt_node->prev = self->tail;
            }

            if (cur && cur->prev) {
                cur->prev->next = isrt_node;
                cur->prev = isrt_node;
            }

            if (index == 0)
                self->head = isrt_node;

            if (index == list_size(self))
                self->tail = isrt_node;
        }

        self->size++;
        list_reset(self);
        return true;
    }

    return false;
}

bool list_delete(List *self, int index)
{
    if (self && index < list_size(self) && index >= 0) {
        int i = 0;
        list_node *cur = self->head;
        while (!list_is_empty(self) && i != index) {
            cur = cur -> next;
            i++;
        }

        if (!list_is_empty(self)) {
            list_node *del_node = cur;
            if (index == 0)
                self->head = del_node->next;

            if (list_size(self) == 1) {
                self->head = NULL;
                self->cur = NULL;
                self->tail = NULL;
            }

            if (del_node->prev)
                del_node->prev->next = del_node->next;

            if (del_node->next)
                del_node->next->prev = del_node->prev;


            free(del_node);
        }

        self->size--;
        list_reset(self);
        return true;
    }

    return false;
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
        self->head->prev = isrt_node;
        isrt_node->next = self->head;
        self->head = isrt_node;
        list_reset(self);
    }

    self->size++;
}

void *list_pop_back(List *self)
{
    if (self) {
        list_node *ret_node = self->tail;
        self->tail = self->tail->prev;
        if (self->tail) {
            void *ret_data = ret_node->data;
            free(ret_node);
            self->size--;
            list_reset(self);
            return ret_data;
        }
    }

    return NULL;
}

void *list_pop_front(List *self)
{
    if (self) {
        list_node *ret_node = self->head;
        self->head = self->head->next;
        if (self->head) {
            void *ret_data = ret_node->data;
            free(ret_node);
            self->size--;
            list_reset(self);
            return ret_data;
        }
    }

    return NULL;
}

void *list_get_back(List *self)
{
    if (self && self->tail)
        return self->tail->data;

    return NULL;
}

void *list_get_front(List *self)
{
    if (self && self->head)
        return self->head->data;

    return NULL;
}

bool list_has_cur(List *self)
{
    if (self && self->cur)
        return true;

    return false;
}

void *list_get_cur(List *self)
{
    if (self && self->cur) {
        return self->cur->data;
    }

    return NULL;
}

bool list_has_next(List *self)
{
    if (self && self->cur && self->cur->next)
        return true;

    return false;
}

void *list_get_next(List *self)
{
    if (self && list_has_next(self)) {
        return self->cur->next->data;
    }

    return NULL;
}

void list_move_next(List *self)
{
    if (self && list_has_cur(self)) {
        self->cur = self->cur->next;
    }
}


bool list_has_prev(List *self)
{
    if (self && self->cur && self->cur->prev)
        return true;

    return false;
}

void *list_get_prev(List *self)
{
    if (self && list_has_prev(self)) {
        return self->cur->prev->data;
    }

    return NULL;
}

void list_move_prev(List *self)
{
    if (self && list_has_cur(self)) {
        self->cur = self->cur->prev;
    }
}


List *new_list(void)
{
    List *ret_list = (List *) malloc(sizeof(List));
    memset(ret_list, 0, sizeof(List));
    return ret_list;
}

void delete_list(List *self)
{
    if (self) {
        while (!list_is_empty(self)) {
            list_pop_back(self);
        }

        free(self);
        self = NULL;
    }
}
