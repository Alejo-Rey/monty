#include "monty.h"
/**
 * pall - funtion to print a double list
 * @head: the head of the list
 * @line_number: line numer.
 * Return: Void.
 */

void pall(stack_t **head, unsigned int line_number)
{
	size_t x;
	stack_t *tmp;

	if (!head || !line_number)
		return;
	tmp = *head;

	for (x = 0; tmp; x++)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
