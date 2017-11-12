#include <stdlib.h>
#include "stack.h"

stack_t *
stack_create(data_dtor_func_t dtor)
{
	return list_create(dtor, NULL);
} // end stack_create()

int
stack_destroy(stack_t *s)
{
	return list_destroy(s);
} // end stack_destroy()

stack_element_t *
stack_push(stack_t *s, stack_element_t *e)
{
	return list_push_front(s, e);
} // end stack_push()

stack_element_t *
stack_pop(stack_t *s)
{
	return list_pop_front(s);
} // end stack_pop()

int 
stack_pop_and_destroy(stack_t *s)
{
	return list_pop_front_and_destroy(s);
} // stack_pop_and_destroy()

stack_element_t *
stack_element_create(void *data)
{
	return list_node_create(data);
} // end stack_element_create()

int
stack_element_destroy(stack_element_t *e)
{
	return list_node_destroy(e);
} // end stack_element_destroy()

stack_len_t
stack_get_lenght(stack_t *s)
{
	return list_get_lenght(s);
} // end stack_get_lenght()

stack_element_t *
stack_peek(stack_t *s)
{
	if (!s || s->len == 0)
	{
		return NULL;
	} // end if
	
	return s->head;
} // end stack_peek()
