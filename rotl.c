#include "monty.h"
/**
  *rotl- rotates the stack to the top
  *@head: stack head
  *@line_number: line_number
  *Return: no return
 */
void rotl(stack_t **head,  __attribute__((unused)) unsigned int line_number)
{
	stack_t *tmp = *head, *connect;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	connect = (*head)->next;
	connect->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = connect;
}
