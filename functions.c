#include "monty.h"
/**
 * isNumeric - A function that verifies if it's a number.
 * @str: string to compare.
 * Return: 0  if it's true or 1 if doesn't.
 */

int isNumeric(const char *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	if (str[0] == 45)
		i++;
	while (str[i] != '\0')
	{

		if (str[i] < 47 || str[i] > 58)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * free_dlistint - function to free a linked list
 * @head: the head of the list
 * Return: non
 */
void free_dlistint(stack_t *head)
{
	if (!head)
		return;
	while (head)
	{
		free(head);
		head = head->next;
	}
}
