#include "main.h"

/**
 * print_char - Prints a character
 * @args: List a of arguments
 * @buffer: Buffer array
 * @flag:  Checks for active flag
 * @width: Width
 * @prec: Precision
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_ch(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	char c = va_arg(args, int);

	return (handle_write_ch(c, buffer, flag, width, prec, size));
}
