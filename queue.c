#include <stdlib.h>
#include "queue.h"

queue_t *
create_queue(data_dtor_func_t dtor)
{
	return create_list(dtor, NULL);
} // end create_queue()

int
destroy_queue(queue_t *q)
{
	return destroy_list(q);
} // end destroy_queue()

queue_element_t *
push_to_queue(queue_t *q, queue_element_t *e)
{
	return add_to_end(q, e);
} // end push_to_queue()

queue_element_t *
pop_from_queue(queue_t *q)
{
	return remove_from_start(q);
} // end pop_from_queue()

int 
pop_from_queue_and_destroy(queue_t *q)
{
	return remove_from_start_and_destroy(q);
} // end pop_from_queue_and_destroy()

queue_element_t *
create_queue_element(void *data)
{
	return create_list_node(data);
} // end create_queue_element()

int
destroy_queue_element(queue_element_t *e)
{
	return destroy_list_node(e);
} // end destroy_queue_element()

queue_len_t
get_queue_lenght(queue_t *q)
{
	return get_list_lenght(q);
} // end get_queue_lenght()
