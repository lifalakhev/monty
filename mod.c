#include "monty.h"

/**
 * mod - computes the rest of the lv_division of the second top element of
 * the stack by the top element of the stack.
 * @head: stack head
 * @line_number: line_number.
 *
 * Return: no return
*/
void mod(stack_t **head, unsigned int line_number)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	connect = h->next->n % h->n;
	h->next->n = connect;
	*head = h->next;
	free(h);
}
