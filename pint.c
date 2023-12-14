#include "monty.h"

/**
 * pint_top - Function that prints the top node of the stack.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void pint_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		era(6, line_number);
	printf("%d\n", (*stack)->n);
}
