#include <stdlib.h>
#include "queue.h"

queue_t *
queue_create(data_dtor_func_t dtor)
{
	return list_create(dtor, NULL);
} // end queue_create()

int
queue_destroy(queue_t *q)
{
	return list_destroy(q);
} // end queue_destroy()

queue_element_t *
queue_push(queue_t *q, queue_element_t *e)
{
	return list_push_back(q, e);
} // end queue_push()

queue_element_t *
queue_pop(queue_t *q)
{
	return list_pop_front(q);
} // end queue_pop()

int 
queue_pop_and_destroy(queue_t *q)
{
	return list_pop_front_and_destroy(q);
} // queue_pop_and_destroy()

queue_element_t *
queue_element_create(void *data)
{
	return list_node_create(data);
} // end queue_element_create()

int
queue_element_destroy(queue_element_t *e)
{
	return list_node_destroy(e);
} // end queue_element_destroy()

queue_len_t
queue_get_lenght(queue_t *q)
{
	return list_get_lenght(q);
} // end queue_get_lenght()

queue_element_t *
queue_peek(queue_t *q)
{
	if (!q || q->len == 0)
	{
		return NULL;
	} // end if
	
	return q->head;
} // end queue_peek()
