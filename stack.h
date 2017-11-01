#ifndef STACK_H
#define STACK_H

#include "list.h"

stack_t *
create_stack(data_dtor_func_t dtor);

int
destroy_stack(stack_t *s);

stack_element_t *
push_to_stack(stack_t *s, stack_element_t *e);

stack_element_t *
pop_from_stack(stack_t *s);

int 
pop_from_stack_and_destroy(stack_t *s);


stack_element_t *
create_stack_element(void *data);

int
destroy_stack_element(stack_element_t *e);

stack_len_t
get_stack_lenght(stack_t *s);

#endif // STACK_H
