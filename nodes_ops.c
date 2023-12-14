#include "monty.h"
stack_t *head = NULL;

/**
 * create_node - Function that creates a node.
 * @n: Number to go into the node.
 *
 * Return: Pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));

	if (node == NULL)
		err(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * free_nodes - Function that frees nodes in the stack.
 */
void free_nodes(void)
{
	stack_t *tmp;
	if (head == NULL)
		return;

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
