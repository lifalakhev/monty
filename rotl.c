#include "monty.h"

/**
 * rotl - Function that rotates the first node of the stack to the bottom.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @linenum: Integer representing the line number of of the opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	(*stack)->prev = tmp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
