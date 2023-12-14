#include "monty.h"

/**
 * nodes_mul - Function that adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void nodes_mul(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		era(8, line_number, "mul");

	(*stack) = (*stack)->next;
	sum = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
