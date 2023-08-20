#include "main.h"

/**
 * print_percent - Prints a modulus sign
 * @args: arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flag
 * @width: width
 * @prec: Precision
 * @size: Size specification
 * 
 * Return: Number of chars printed
 */
int print_mod(va_list args, char buffer[],
	int flag, int width, int prec, int size)
{
	UNUSED(args);
	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
    
	return (write(1, "%%", 1));
}
