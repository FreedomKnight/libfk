#include "fk_list.h"

typedef List Stack;
typedef list_node stack_node;

bool stack_is_empty(Stack *self)
{
    return list_is_empty(self);
}

int stack_size(Stack *self)
{
    return list_size(self);
}

void stack_push(Stack *self, stack_node *node)
{
    list_push_front(self, node);
}

void *stack_pop(Stack *self)
{
    return list_pop_front(self);
}

void *stack_get_top(Stack *self)
{
    return list_get_front(self);
}
