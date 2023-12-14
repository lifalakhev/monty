#include "monty.h"
/**
  *sub- stration
  *@head: stack head
  *@line_number: line_number
  *Return: no return
 */
void sub(stack_t **head, unsigned int line_number)
{
	stack_t *connect;
	int s, nodes;

	connect = *head;
	for (nodes = 0; connect != NULL; nodes++)
		connect = connect->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	connect = *head;
	s = connect->next->n - connect->n;
	connect->next->n = s;
	*head = connect->next;
	free(connect);
}
