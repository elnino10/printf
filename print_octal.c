#include "main.h"

/**
 * print_octal - Prints unsigned integer in octal
 * @args: Arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flags
 * @width: get width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: printed character
 */
int print_octal(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{

	int index = BUFF_SIZE - 2;
	unsigned long int num = va_arg(args, unsigned long int);
	unsigned long int init_n = num;

	VOID(width);

	num = convert_unsigned(num, size);

	if (num == 0)
		buffer[index--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[index--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & F_HASH && init_n != 0)
		buffer[index--] = '0';

	index++;

	return (write_unsigned(0, index, buffer, flag, width, prec, size));
}

