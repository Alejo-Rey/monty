#include "monty.h"
/**
 *
 *
 */

int isNumeric(const char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}