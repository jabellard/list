#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef list_node_t queue_element_t;

typedef list_len_t queue_len_t;

typedef list_t queue_t;

queue_t *
create_queue(data_dtor_func_t dtor);

int
destroy_queue(queue_t *q);

queue_element_t *
push_to_queue(queue_t *q, queue_element_t *e);

queue_element_t *
pop_from_queue(queue_t *q);

int 
pop_from_queue_and_destroy(queue_t *q);


queue_element_t *
create_queue_element(void *data);

int
destroy_queue_element(queue_element_t *e);

queue_len_t
get_queue_lenght(queue_t *q);

#endif // QUEUE_H
