#include "main.h"

/**
 * print_int - Prints integers
 * @args: Arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flags
 * @width: get width
 * @prec: Precision
 * @size: Size
 *
 * Return: Count of printed characters
 */
int print_int(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	int negative = 0;
	long int n = va_arg(args, long int);
	unsigned long int num;

	n = convert_num_size(n, size);
	if (n == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;
	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;

	return (write_number_handler(negative, i, buffer, flag, width, prec, size));
}

