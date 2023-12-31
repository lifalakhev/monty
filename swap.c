#include "monty.h"

/**
 * nodes_swap - Function that swaps the top two elements of the stack.
 * @stack: Pointer to a pointer pointing top node of the stack.
 * @line_number: Integer representing the line number of of the opcode.
 */
void nodes_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		era(8, line_number, "swap");
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
