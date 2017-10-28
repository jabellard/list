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
	return 0;
} // end free_data


int matchf(list_node_t *n, void *data)
{
	if (!n || !data)
	{
		return 0;
	} // end if
	if (strcmp(((test_data_t *)n->data)->str, ((test_data_t *)data)->str) == 0)
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
	test_data_t *d0 = create_test_data("data new");
	list_node_t *n0 = create_list_node((void *) d0);
	
	test_data_t *d1 = create_test_data("data 1");
	list_node_t *n1 = create_list_node((void *) d1);
	
	test_data_t *d2 = create_test_data("data 2");
	list_node_t *n2 = create_list_node((void *) d2);

	test_data_t *d3 = create_test_data("data 3");
	list_node_t *n3 = create_list_node((void *) d3);

	test_data_t *d4 = create_test_data("data 4");
	list_node_t *n4 = create_list_node((void *) d4);

	test_data_t *d5 = create_test_data("data 5");
	list_node_t *n5 = create_list_node((void *) d5);
	
	// add nodes to the list -------------------------------
	add_to_end(l1, n1);
	add_to_end(l1, n2);
	add_to_end(l1, n3);
	add_to_end(l1, n4);
	add_to_end(l1, n5);
	insert_after_node(n5, n0);
	
	printf("list lenght1 = %d\n", l1->len);
	// removal--------------------------------------------
	int res = remove_and_destroy_list_node(n1);
	printf("result = %d\n", res);
	printf("list lenght2 = %d\n", l1->len);
	
	//remove_list_node(n4);
	
	
	// create a list iterator
	list_iterator_t *it = create_list_iterator(l1, HEAD);
	
	// traverse the list, printing the node values---------------
	list_node_t *node;
	while((node = list_iterator_next(it)))
	{
		printf("data value = %s\n", ((test_data_t *)node->data)->str);
	} // end while
	printf("list lenght3 = %d\n", l1->len);
	
	// searching -----------------------------
	list_node_t *result = find_node_at_index(l1, 5);
	if (result)
	{
		printf("search result = %s\n", ((test_data_t *)result->data)->str);
	} // end if
	
	// destroy the list iterator
	
	
	// destory the list

	
	return 0;
} // end main
