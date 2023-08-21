#include "main.h"

/**
 * print_binary - Prints binary representation of an unsigned number
 * @args: Arguments list
 * @buffer: Buffer array to handle print
 * @flag:  Checks for active flags
 * @width: width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: Count of characters printed
 */
int print_bin(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	unsigned int num, max, sum, i;
	unsigned int arr[32];
	int ch_count;

	VOID(buffer);
	VOID(flag);
	VOID(width);
	VOID(prec);
	VOID(size);

	num = va_arg(args, unsigned int);
	max = 2147483648; /* (2 ^ 31) */
	arr[0] = num / max;

	for (i = 1; i < 32; i++)
	{
		max = max / 2;
		arr[i] = (num / max) % 2;
	}
	for (i = 0, sum = 0, ch_count = 0; i < 32; i++)
	{
		sum += arr[i];
		if (sum || i == 31)
		{
			char b = '0' + arr[i];

			write(1, &b, 1);
			ch_count++;
		}
	}

	return (ch_count);
}

