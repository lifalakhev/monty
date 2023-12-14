#include "monty.h"

/**
 * pop_t - Function that adds a node to the stack.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void pop_t(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
		era(7, line_number);

	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
