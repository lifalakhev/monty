#include "monty.h"

/**
 * pstr - Function that prints a string.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @linenum: Integer representing the line number of of the opcode.
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	int characters;
	stack_t *tmp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
        }
	tmp = *stack;

	while (tmp != NULL)
	{
		characters = tmp->n;
		if (characters <= 0 || characters > 127)
			break;
		printf("%c", characters);
		tmp = tmp->next;
	}
	printf("\n");
}
