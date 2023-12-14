#include "monty.h"

/**
 * rotr - Function that rotates the last node of the stack to the top.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @linenum: Integer representing the line number of of the opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int linenum)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;
	tmp = *stack;

	while (tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = *stack;
	tmp->prev->next = NULL;
	tmp->prev = NULL;
	(*stack)->prev = tmp;
	(*stack) = tmp;
}
