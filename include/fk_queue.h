#ifndef FK_QUEUE_H
#define FK_QUEUE_H

#include "fk_list.h"

typedef List Queue;
typedef list_node queue_node;

bool queue_is_empty(Queue *self);
int queue_size(Queue *self);
void queue_push(Queue *self);
void *queue_pop(Queue *self);
void *queue_get_top(Queue *self);
#endif
