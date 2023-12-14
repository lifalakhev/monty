#include "monty.h"
/**
 * queue - prints the top
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	bus.lifi = 1;
}

/**
 * add_queue - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void add_queue(stack_t **head, int n)
{
	stack_t *new_node, *connect;

	connect = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (connect)
	{
		while (connect->next)
			connect = connect->next;
	}
	if (!connect)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		connect->next = new_node;
		new_node->prev = connect;
	}
}
