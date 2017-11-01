#include <stdlib.h>
#include "stack.h"

stack_t *
create_stack(data_dtor_func_t dtor)
{
	return create_list(dtor, NULL);
} // end create_stack()

int
destroy_stack(stack_t *s)
{
	return destroy_list(s);
} // end destroy_stack()

stack_element_t *
push_to_stack(stack_t *s, stack_element_t *e)
{
	return add_to_start(s, e);
} // end push_to_stack()

stack_element_t *
pop_from_stack(stack_t *s)
{
	return remove_from_start(s);
} // end pop_from_stack()

int 
pop_from_stack_and_destroy(stack_t *s)
{
	return remove_from_start_and_destroy(s);
} // end pop_from_stack_and_destroy()

stack_element_t *
create_stack_element(void *data)
{
	return create_list_node(data);
} // end create_stack_element()

int
destroy_stack_element(stack_element_t *e)
{
	return destroy_list_node(e);
} // end destroy_stack_element()

stack_len_t
get_stack_lenght(stack_t *s)
{
	return get_list_lenght(s);
} // end get_stack_lenght()
