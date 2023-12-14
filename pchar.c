#include "monty.h"

/**
 * pchar - Function that prints the Ascii characters.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	int characters;

	if (stack == NULL || *stack == NULL)
		strerr(11, line_number);
	characters = (*stack)->n;

	if (characters < 0 || characters > 127)
		strerr(10, line_number);
	printf("%c\n", characters);
}
