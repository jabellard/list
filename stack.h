#ifndef STACK_H
#define STACK_H

#include "list.h"

typedef list_node_t stack_element_t;

typedef list_len_t stack_len_t;

typedef list_t stack_t;

stack_t *
stack_create(data_dtor_func_t dtor);

int
stack_destroy(stack_t *s);

stack_element_t *
stack_push(stack_t *s, stack_element_t *e);

stack_element_t *
stack_pop(stack_t *s);

int 
stack_pop_and_destroy(stack_t *s);

stack_element_t *
stack_element_create(void *data);

int
stack_element_destroy(stack_element_t *e);

stack_len_t
stack_get_lenght(stack_t *s);

stack_element_t *
stack_peek(stack_t *s);

#endif // STACK_H
