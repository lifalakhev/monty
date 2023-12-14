#include "monty.h"

/**
 * add_que - Adds a node to the queue.
 * @new_node: Pointer to the new node.
 * @linenum: line number of the opcode.
 */
void add_que(stack_t **new_node, __attribute__((unused))unsigned int linenum)
{
	stack_t *tmp;

	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;

	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *new_node;
	(*new_node)->prev = tmp;

}
