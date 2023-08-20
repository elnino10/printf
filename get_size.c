#include "main.h"

/**
 * get_size - Gets the size to the argument
 * @format: Formatted string of the arguments
 * @a: List of arguments
 *
 * Return: size
 */
int get_size(const char *format, int *a)
{
	int index = *a + 1;
	int size = 0;

	if (format[index] == 'l')
		size = S_LONG;
	else if (format[index] == 'h')
		size = S_SHORT;

	if (size == 0)
		*a = index - 1;
	else
		*a = index;

	return (size);
}

