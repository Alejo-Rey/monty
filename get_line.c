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
	char * msg = " unknown instruction ";
	instruction_t inst[] = {
		{"pall", pall},
		{"push", push},
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
				if (strcmp(inst[count].opcode, token) == 0)
				{
					inst[count].f(&head, ++line_number);
					break;
				}
				else
					fprintf(stderr, "L%d:%s%s\n",line_number, msg, buf);
			}
		}
	}
	free_dlistint(head);
	free(buf);
	return (0);
}
