#include "monty.h"
int number = 0;

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(int ac, char **av)
{
	int line_number = 0, count;
	FILE *file;
	char *buf = NULL, *token;
	size_t buf_int = 0;
	stack_t *head = NULL;
	instruction_t inst[] = {
		{"push", push},
		{"pall", pall},
		{NULL, NULL}
		};

	file = fopen(av[1], "r+");

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit (EXIT_FAILURE);
	}
	while (-1 != getline(&buf, &buf_int, file))
	{
		token = strtok(buf, " \n");
		while (token != NULL)
		{

			for (count = 0; inst[count].opcode != NULL; count++)
			{
				if (strcmp(inst[count].opcode, token) == 0)
				{
					inst[count].f(&head, ++line_number);
					//printf("token = %s inst = %s\n", token, inst[count].opcode);
				}
			}
			token = strtok(NULL, " \n");
			if (token == NULL)
			{
				break;
			}
			if (strlen(token) == 1)
			{
				if (isNumeric(token) == 0)
				{
					number = atoi(token);
				}
				else
					printf("EL token es = %s\n",token);
			}
			else
				continue;
		}
		//printf("%d : %s\n", ++line_number, buf);
	}

	return (0);
}
