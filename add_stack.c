#include "monty.h"

/**
 * pstck - function that adds a node to the stack.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @line_number: integer representing line number of  the opcode.
 */
void pstck(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
