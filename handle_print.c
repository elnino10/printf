#include "main.h"

/**
 * handle_print - Prints an argument by type
 * @fmt: Formatted string
 * @args: Arguments list
 * @arr: arr pointer
 * @buffer: Buffer array
 * @flag: Checks for active flag
 * @width: Width
 * @prec: Precisions
 * @size: Size specification
 *
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *arr, va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	int i, len = 0, prints = -1;

	format fmt_type[] = {
		{'c', print_ch}, {'s', print_str}, {'%', print_mod},
		{'i', print_int}, {'d', print_int}, {'b', print_bin},
		{'u', print_unsigned}, {'o', print_octal},
		{'x', print_hexa_lower}, {'X', print_hexa_upper},
		{'p', print_pointer}, {'r', print_reverse}, {'\0', NULL}
	};
	for (i = 0; fmt_type[i].fmt != '\0'; i++)
		if (fmt[*arr] == fmt_type[i].fmt)
			return (fmt_type[i].f(args, buffer, flag, width, prec, size));
	if (fmt_type[i].fmt == '\0')
	{
		if (fmt[*arr] == '\0')
			return (-1);
		len += write(1, "%%", 1);
		if (fmt[*arr - 1] == ' ')
			len += write(1, " ", 1);
		else if (width)
		{
			(*arr)--;
			while (fmt[*arr] != ' ' && fmt[*arr] != '%')
				(*arr)--;
			if (fmt[*arr] == ' ')
				(*arr)--;
			return (1);
		}
		len += write(1, &fmt[*arr], 1);
		return (len);
	}
	return (prints);
}

