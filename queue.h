#ifndef QUEUE_H
#define QUEUE_H

#include "list.h"

typedef list_node_t queue_element_t;

typedef list_len_t queue_len_t;

typedef list_t queue_t;

queue_t *
queue_create(data_dtor_func_t dtor);

int
queue_destroy(queue_t *q);

queue_element_t *
queue_push(queue_t *q, queue_element_t *e);

queue_element_t *
queue_pop(queue_t *q);

int 
queue_pop_and_destroy(queue_t *q);


queue_element_t *
queue_element_create(void *data);

int
queue_element_destroy(queue_element_t *e);

queue_len_t
queue_get_lenght(queue_t *q);

queue_element_t *
queue_peek(queue_t *q);

#endif // QUEUE_H
