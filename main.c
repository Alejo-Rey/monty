#include "monty.h"
int number = 0;
/**
 * main - check the code for Holberton School students.
 * @ac: arguments count
 * @av: argument vector
 * Return: Always 0.
 */
int main(int ac, char **av)
{
	FILE *file;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r+");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	get_line(file);
	fclose(file);
	return (0);
}
