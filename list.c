#include <stdlib.h>
#include "list.h"

list_t * 
create_list(free_func_t free, match_func_t match)
{
	list_t *l = malloc(sizeof(list_t));
	if (!l)
	{
		return NULL;
	} // end if
	
	l->head = NULL;
	l->tail = NULL;
	l->len = 0;
	l->free = free;
	l->match = match;
	
	return l;
} // end create_list()

void 
destroy_list(list_t *l)
{
	list_len_t len = l->len;
	list_node_t *curr = l->head;
	list_node_t *next = NULL;
	
	while (len--)
	{
		next = curr->next;
		destroy_list_node(l, curr);
		//sfree(curr); // needed??? NOOOOOOOOOOOOO!!!
		curr = next;
	} // end while
	
	free(l);
	
} // end destroy_list()

list_node_t *
add_to_end(list_t *l, list_node_t *n)
{
	if (!l || !n)
	{
		return NULL;
	} // end if
	
	if (l->len)
	{
		n->prev = l->tail;
		n->next = NULL;
		l->tail->next = n;
		l->tail = n;
	} // end if
	else
	{
		n->prev = NULL;
		n->next = NULL;
		l->head = n;
		l->tail = n;
	} // end else
	
	(l->len)++;
	return n;
} // end add_to_end()


list_node_t *
remove_from_end(list_t *l)
{
	if (!l->len)
	{
		return NULL;
	} // end if
	
	list_node_t *n = l->tail;
	
	if (--(l->len))
	{
		l->tail = n->prev;
		l->tail->next = NULL;
	} // end if
	else
	{
		l->head = NULL;
		l->tail = NULL;
	} // end else
	
	n->prev = NULL;
	n->next = NULL;
	return n;
} // end remove_from_end()


int
remove_from_end_and_destroy(list_t *l)
{
	list_node_t *n = remove_from_end(l);
	if (!n)
	{
		return -1;
	} // end if
	
	return destroy_list_node(l, n);
} // end remove_from_end_and_destroy()


list_node_t *
add_to_start(list_t *l, list_node_t *n)
{
	if (!l || !n)
	{
		return NULL;
	} // end if
	
	if (l->len)
	{
		n->prev = NULL;
		n->next = l->head;
		l->head->prev = n;
		l->head = n;
	} // end if
	else
	{
		n->prev = NULL;
		n->next = NULL;
		l->head = n;
		l->tail = n;
	} //end else
	
	(l->len)++;
	return n;
} // end add_to_start()

list_node_t *
remove_from_start(list_t *l)
{
	if (!l->len)
	{
		return NULL;
	} // end if
	
	list_node_t *n = l->head;
	
	if (--(l->len))
	{
		l->head = n->next;
		l->head->prev = NULL;
	} // end if
	else
	{
		l->head = NULL;
		l->tail = NULL;
	} // end else
	
	n->prev = NULL;
	n->next = NULL;
	// ---------------- delete node?
	
	// decrement list lenght
	return n;
} // end remove_from_start()

int
remove_from_start_and_destroy(list_t *l)
{
	list_node_t *n = remove_from_start(l);
	if (!n)
	{
		return -1;
	} // end if
	
	return destroy_list_node(l, n);
} // end remove_from_start_and_destroy()

list_node_t *
remove_list_node(list_t *l, list_node_t *n)
{
	if (!l || !n)
	{
		return NULL;
	} // end if
	else if (l->head == n)
	{
		return remove_from_start(l);
	} // else if
	else if (l->tail == n)
	{
		return remove_from_end(l)
	} // end else if
	else
	{
		list_node_t *temp = n->prev;
		if (n->prev)
		{
			n->prev->next = n->next;
			n->prev = NULL;
		} // end if
		
		if (n->next)
		{
			n->next->prev = temp;
			n->next = NULL;
		} // end if
		
		return n;
	} // end else
} // end remove_list_node()

int 
remove_and_destroy_list_node(list_t *l, list_t *l, list_node_t *n)
{
	list_node_t *node = remove_list_node(l, n);
	
	return destroy_list_node(node);
} // end remove_and_destroy_list_node()

list_node_t *
insert_before_node(list_t *l, list_node_t *old, list_node_t *new)
{
	if (!l || !old || !new)
	{
		return NULL;
	} // end if
	else if (l->head == old)
	{
		add_to_start(l, new);
	} // end else if
	else if (l->tail == old)
	{
		if (l->len == 1)
		{
			new->prev = NULL;
			l->head = new;
			l->tail->prev = new;
			
		} // end if
		else
		{
			list_node_t *temp = l->tail->prev;
			new->prev = temp;
			new->next = l->tail;
			l->tail->prev = new;
			temp->next = new;
			
		} // end else
	} // end else if
	else
	{
		list_node_t *temp = old->prev;
		new->prev = temp;
		new->next = old;
		old->prev = new;
		tem->next = new;
		
	} // end else
	
	(l->len)++;
	return new;
} // end insert_before_node()

list_node_t *
insert_after_node(list_node_t *old, list_node_t *new)
{

} // end insert_after_node()
list_iterator_t *
create_list_iterator(list_t *l, list_direction_t d)
{
	if (l->len == 0)
	{
		return NULL;
	} // end if
	
	list_iterator_t *it = malloc(sizeof(list_iterator_t));
	if (!it)
	{
		return NULL;
	} // end if
	
	it->direction = d;
	
	if (d == HEAD)
	{
		it->next = l->head;
	} // end if
	else
	{
		it->next = l->tail;
	} // end else
	
	return it;
} // end create_list_iterator()

list_node_t *
list_iterator_next(list_iterator_t *it)
{
	list_node_t *curr = it->next;
	
	if (curr)
	{
		if (it->direction == HEAD)
		{
			it->next = curr->next;
		} // end if
		else
		{
			it->next = curr->prev;
		} // end else
	} // end if
	
	return curr;
} // end list_iterator_next()

void 
destroy_list_iterator(list_iterator_t *it)
{
	sfree(it);
} // end destroy_list_iterator()

list_node_t *
create_list_node(void *data)
{
	list_node_t *n = malloc(sizeof(list_node_t));
	if (!n)
	{
		return NULL;
	} // end if
	
	n->prev = NULL;
	n->next = NULL;
	n->data = data;
	return n;
} // end create_list_node()

int 
destroy_list_node(list_t *l, list_node_t *n)
{
	if (!l->free)
	{
		return -1;
	} // end if
	
	return l->free(n);
} // end destroy_list_node()

list_node_t *
find_node_by_value(list_t *l, void *v)
{
	if (!l->match)
	{
		return NULL;
	} // end if
	
	list_iterator_t *it = create_list_iterator(l, HEAD);
	if (!it)
	{
		return NULL;
	} // end if
	
	list_node_t *n;
	
	while ((n = list_iterator_next(it)))
	{
		if (l->match(v, n))
		{
			destroy_list_iterator(it);
			return n;
		} // end if
	} // end while
	
	destroy_list_iterator(it);
	return NULL;
} // end find_node_by_value()

/*
list_node_t *
find_node_at_index(list_t *l, int i)
{
	
	list_direction_t d = HEAD;
	
	if ()
	{
	
	} // end if
	
	if  ()
	{
		list_iteartor_t *it = create_list_iterator(l, d);
		if (!it)
		{
			return NULL;
		} // end if
		
		list_node_t *n = list_iterator_next(it);
		while (index--)
		{
			n = list_iterator_next(it);
		} // end while
		
	}
	
	return NULL;
} // end find_node_at_index()




*/

//------------------------------------------
void safe_free(void **pp)
{
	if (pp != NULL && *pp != NULL)
	{
		free(*pp);
		*pp = NULL;
	} // end if
}// end safe_free












