#include "monty.h"
/**
 * get_line - function to get in lines the file
 * @file: the file to convert in lines
 * Return: 0 in success
 */
int get_line(FILE *file)
{
	int line_number = 0;
	stack_t *head = NULL;
	char *buf = NULL, *token, *temp, *msg = ": usage: push integer";
	char *p = "push";
	size_t buf_int = 0;

	while (-1 != getline(&buf, &buf_int, file))
	{
		token = strtok(buf, " \n");
		temp = strtok(NULL, " \n");

		if (isNumeric(temp) == 0)
			number = atoi(temp);
		else if (token && strcmp(token, p) == 0 && isNumeric(temp) != 0)
		{
			fprintf(stderr, "L%d%s\n", ++line_number, msg);
			exit(EXIT_FAILURE);
		}
		if (token != NULL)
		{
			if (_execute(&head, token, line_number) != 1)
				line_number++;
		}
	}
	free_dlistint(head);
	free(buf);
	return (0);
}
