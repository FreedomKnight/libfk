#ifndef FK_STACK_H
#define FK_STACK_H

#include "fk_list.h"

typedef List Stack;
typedef list_node stack_node;

bool stack_is_empty(Stack *self);
int stack_size(Stack *self);
void stack_push(Stack *self);
void *stack_pop(Stack *self);
void *stack_get_top(Stack *self);

#endif
