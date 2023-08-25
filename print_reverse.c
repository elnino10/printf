#include "main.h"

/**
 * print_reverse - Prints string in reverse
 * @args: Arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flags
 * @width: get width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: count of chars printed
 */

int print_reverse(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	char *str;
	int index, count = 0;

	VOID(buffer);
	VOID(flag);
	VOID(width);
	VOID(size);
	VOID(prec);

	str = va_arg(args, char *);

	if (str == NULL)
	{
		str = ")Null(";
	}
	for (index = 0; str[index]; index++)
		;

	for (index = index - 1; index >= 0; index--)
	{
		char z = str[index];

		write(1, &z, 1);
		count++;
	}

	return (count);
}

