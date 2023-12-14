#include "monty.h"

/**
 * nodes_div - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void nodes_div(stack_t **stack, unsigned int line_number)
{
	int sum;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		era(8, line_number, "div");

	if ((*stack)->n == 0)
		era(9, line_number);
	(*stack) = (*stack)->next;
	sum = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = sum;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
