#include "monty.h"
/**
 * push - funtion to add a node in the beginnig of the list
 * @head: the head of the list
 * @line_number: Line number.
 * Return: Void.
 */

void push(stack_t **head, unsigned int line_number)
{
	stack_t *t;

	t = malloc(sizeof(stack_t));
	if (!t || !line_number)
		return;
	t->n = number;
	t->next = *head;
	t->prev = NULL;
	if (*head)
		(*head)->prev = t;
	*head = t;
}
