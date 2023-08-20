#include "main.h"


/**
 * print_string - Prints a string
 * @args: List a of arguments
 * @buffer: Buffer array to handle print
 * @flag:  Calculates active flags
 * @width: get width.
 * @prec: Precision specification
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int print_str(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	int len = 0, i;
	char *s = va_arg(args, char *);

	UNUSED(buffer);
	UNUSED(flag);
	UNUSED(width);
	UNUSED(prec);
	UNUSED(size);
	if (s == NULL)
	{
		s = "(null)";
		if (prec >= 6)
			s = "      ";
	}
	while (s[len] != '\0')
		len++;
	if (prec >= 0 && prec < len)
		len = prec;
	if (width > len)
	{
		if (flag & F_MINUS)
		{
			write(1, &s[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], len);
			return (width);
		}
	}

	return (write(1, s, len));
}
