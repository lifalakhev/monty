#include "monty.h"

/**
 * lv_pint - prints the top
 * @head: stack head
 * @line_number: line number
 * Return: no return.
*/
void lv_pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
