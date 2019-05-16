#include "monty.h"
/**
 *
 *
 *
 */
int get_line(FILE *file)
{
	int line_number = 0, count;
	char *buf = NULL, *token, *temp;
	size_t  buf_int = 0;
	stack_t *head = NULL;
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
	};
	while (-1 != getline(&buf, &buf_int, file))
	{
		token = strtok(buf, " \n");
		temp = strtok(NULL, " \n");
		if (token != NULL)
		{
			if (isNumeric(temp) == 0)
				number = atoi(temp);
			for (count = 0; inst[count].opcode != NULL; count++)
			{
				if (strcmp(inst[count].opcode, buf) == 0)
					inst[count].f(&head, ++line_number);
			}
		}
	}
	free_dlistint(head);
	free(buf);
	return(0);
}
