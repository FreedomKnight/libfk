#include "fk_list.h"

typedef List Queue;
typedef list_node queue_node;

bool queue_is_empty(Queue *self)
{
    return list_is_empty(self);
}

int queue_size(Queue *self)
{
    return list_size(self);
}

void queue_push(Queue *self, queue_node *node)
{
    list_push_back(self, node);
}

void *queue_pop(Queue *self)
{
    return list_pop_front(self);
}

void *queue_get_top(Queue *self)
{
    return list_get_front(self);
}
