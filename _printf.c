#include "main.h"

/**
 * _printf - prints results according to format
 * @format: format of the input
 *
 * Return: return the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, ch_count = 0, b_index = 0, prints = 0, width, precision, flags,
size;
	char buffer[BUFF_SIZE];
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			print_buff(buffer, &b_index);
			flags = get_flag(format, &i);
			width = get_width(format, &i, args);
			precision = get_prec(format, &i, args);
			size = get_size(format, &i);
			i++;
			prints = handle_print(format, &i, args, buffer,
					flags, width, precision, size);
			if (prints == -1)
				return (-1);
			ch_count += prints;
		}
		else
		{
			buffer[b_index++] = format[i];
			if (b_index == BUFF_SIZE)
				print_buff(buffer, &b_index);
			ch_count++;
		}
		i++;
	}
	print_buff(buffer, &b_index);
	va_end(args);
	return (ch_count);
}

/**
 * print_buff - Prints the contents of the buffer if availbale
 * @buffer: Array of chars
 * @b_index: Index to add next character, represents the length.
 */
void print_buff(char buffer[], int *b_index)
{
	if (*b_index > 0)
		write(1, &buffer[0], *b_index);

	*b_index = 0;
}

