
#include "main.h"
/**
 * handle_print - Prints an argument by type
 * @fmt: Formatted string
 * @args: Arguments list
 * @ind: ind
 * @buffer: Buffer array
 * @flag: Checks for active flag
 * @width: Width
 * @prec: Precisions
 * @size: Size specifification
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *ind, va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	int i, unknow_len = 0, prints = -1;

	format fmt_type[] = {
		{'c', print_ch}, {'s', print_str}, {'%', print_mod},
		{'\0', NULL}
	};
	for (i = 0; fmt_type[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_type[i].fmt)
			return (fmt_type[i].f(args, buffer, flag, width, prec, size));

	if (fmt_type[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (prints);
}

