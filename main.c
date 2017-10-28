#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "list.h"

typedef struct test_data
{
	char *str;
}test_data_t;

test_data_t * create_test_data(const char *str)
{
	test_data_t *td = malloc(sizeof(test_data_t));
	if (!td)
	{
		return NULL;
	} // end if
	
	td->str = strdup(str);
	
	return td;
	
} // end create_test_data()

int free_data(list_node_t *n)
{
	sfree(n->data);
	sfree(n); // nessasary????
} // end free_data


int matchf(list_node_t *n, void *data)
{
	if (strcmp(((test_data_t *)n->data)->str, (const char *) data) == 0)
	{
		return 1;
	} // end if
	
	return 0;
} // end matchf()

int main()
{
	// create a list
	list_t *l1 = create_list(free_data, matchf);
	
	// create node elements
	test_data_t *d1 = create_test_data("data 1");
	list_node_t *n1 = create_list_node((void *) d1);
	
	test_data_t *d2 = create_test_data("data 2");
	list_node_t *n2 = create_list_node((void *) d2);
	
	// add nodes to the list
	add_to_end(l1, n1);
	add_to_end(l1, n2);
	
	// create a list iterator
	list_iterator_t *it = create_list_iterator(l1, HEAD);
	
	// traverse the list, printing the node values
	list_node_t *node;
	while((node = list_iterator_next(it)))
	{
		printf("data value = %s\n", ((test_data_t *)node->data)->str);
	} // end while
	
	// destroy the list iterator
	
	
	// destory the list

	
	return 0;
} // end main
