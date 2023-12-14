#include "monty.h"

/**
 * nodes_sub - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nodes_sub(stack_t **stack, unsigned int line_number)
{
	int sum;
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		era(8, line_number, "sub");

	(*stack) = (*stack)->next;
	sum = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
