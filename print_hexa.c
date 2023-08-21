#include "main.h"

/**
 * print_hexa_num - Prints hexadecimal number in lower or upper
 * @args: Arguments list
 * @map_num: Array of values to map number to
 * @buffer: Buffer array
 * @flag:  Checks for active flag
 * @flag_ch: Calculates active flags
 * @width: get width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: Number of chars printed
 */
int print_hexa_num(va_list args, char map_num[], char buffer[],
		int flag, char flag_ch, int width, int prec, int size)
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
		buffer[index--] = map_num[num % 16];
		num /= 16;
	}
	if (flag & F_HASH && init_n != 0)
	{
		buffer[index--] = flag_ch;
		buffer[index--] = '0';
	}
	index++;

	return (write_unsigned(0, index, buffer, flag, width, prec, size));
}

/**
 * print_hexa_lower - Prints unsigned integer in hexadecimal
 * @args: Arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flag
 * @width: get width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: Hexa format
 */
int print_hexa_lower(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	return (print_hexa_num(args, "0123456789abcdef", buffer,
				flag, 'x', width, prec, size));
}

/**
 * print_hexa_upper - Prints unsigned interger in uppercase hexadecimal
 * @args: Arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flags
 * @width: get width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: hexa format
 */
int print_hexa_upper(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	return (print_hexa_num(args, "0123456789ABCDEF", buffer,
				flag, 'X', width, prec, size));
}

