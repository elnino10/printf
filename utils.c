#include "main.h"

/**
 * is_digit - checks if a char is a digit
 * @c: Char to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}
