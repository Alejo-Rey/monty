#include "monty.h"

/**
 * _execute - Afunction that executes: Push, pall.
 * @head: ponter to the head of the list.
 * @token: pointer char that points to the str.
 * @line_number: line execution
 * Return: 0 if succes, 1 if it doesn't.
 */

int _execute(stack_t **head, char *token, int line_number)
{
	int count, sw = 0;
	char *m = " unknown instruction ";
	instruction_t inst[] = {
		{"pall", pall},
		{"push", push},
		{NULL, NULL}
	};

	for (count = 0; inst[count].opcode != NULL; count++)
	{
		if (strcmp(inst[count].opcode, token) == 0)
		{
			sw = 1;
			break;
		}
	}
	if (sw == 1)
		inst[count].f(head, ++line_number);
	else
		fprintf(stderr, "L%d:%s%s\n", ++line_number, m, token);
	return (0);
}
