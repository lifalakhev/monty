#include "monty.h"

/**
 * mul - multiplies the top two elements of the stack.
 * @head: stack head
 * @line_number: line_number
 * Return: no return
*/
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *h;
	int len = 0, connect;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	connect = h->next->n * h->n;
	h->next->n = connect;
	*head = h->next;
	free(h);
}
