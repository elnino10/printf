#include "main.h"

/**
 * print_unsigned - Prints an unsigned integer
 * @args: Arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flags
 * @width: get width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: unsigned value
 */
int print_unsigned(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);

	num = convert_unsigned(num, size);

	if (num == 0)
		buffer[index--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[index--] = (num % 10) + '0';
		num /= 10;
	}
	index++;

	return (write_unsigned(0, index, buffer, flag, width, prec, size));
}

