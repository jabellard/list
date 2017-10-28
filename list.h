#ifndef LIST_H
#define LIST_H

typedef  struct _list_node
{
	struct _list_node *prev;
	struct _list_node *next;
	void *data;
}list_node_t;

typedef int (*free_func_t)(list_node_t *);
typedef int (*match_func_t)(list_node_t *, void *);
typedef unsigned int list_len_t;
typedef struct 
{
	list_node_t *head;
	list_node_t *tail;
	list_len_t len;
	free_func_t free;
	match_func_t match;
	//
}list_t;

typedef enum
{
	HEAD,
	TAIL
}list_direction_t;

typedef struct 
{
	list_node_t *next;
	list_direction_t direction;
}list_iterator_t;

//---------------------------------------

list_t * 
create_list(free_func_t free, match_func_t match);

void 
destroy_list(list_t *l);

list_node_t *
add_to_end(list_t *l, list_node_t *n);

list_node_t *
remove_from_end(list_t *l);

int
remove_from_end_and_destroy(list_t *l);

list_node_t *
add_to_start(list_t *l, list_node_t *n);

list_node_t *
remove_from_start(list_t *l);

list_node_t *
remove_list_node(list_t *l, list_node_t *n);

int 
remove_and_destroy_list_node(list_t *l, list_node_t *n);


list_node_t *
insert_before_node(list_t *l, list_node_t *old, list_node_t *new);

list_node_t *
insert_after_node(list_t *l, list_node_t *old, list_node_t *new);

int
remove_from_start_and_destroy(list_t *l);


list_node_t *
find_node_by_value(list_t *l, void *v);

list_iterator_t *
create_list_iterator(list_t *l, list_direction_t d);

list_node_t *
list_iterator_next(list_iterator_t *it);


void 
destroy_list_iterator(list_iterator_t *it);

list_node_t *
create_list_node(void *data);

int 
destroy_list_node(list_t *l, list_node_t *n);

list_node_t *
find_node_at_index(list_t *l, list_len_t i);

// -----------------------------------------
void safe_free(void **pp);
#define sfree(p) safe_free((void**)&(p))


#endif // LIST_H
