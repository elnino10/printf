#include "main.h"

/**
 * _printf - prints results according to format
 * @format: format of the input
 *
 * Return: return the number of characters printed
 */
int _printf(const char *format, ...)
{
	int ch_count = 0, b_index = 0;
	const char *ptr;
	char buffer[BUFF_SIZE];
	va_list args;

	ptr = format;
	va_start(args, format);

	ptr = format;
	if (format == NULL)
		return (-1);
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			print_buff(buffer, &b_index);
			ptr++;
		}
		else
		{
			buffer[b_index++] = *ptr;
			if (b_index == BUFF_SIZE)
				print_buff(buffer, &b_index);
			ch_count++;
		}
		ptr++;
	}

	print_buff(buffer, &b_index);

	va_end(args);
	return (ch_count);
}

/**
 * print_buffer - Prints the contents of the buffer if it exist
 * @buffer: Array of chars
 * @buff_ind: Index at which to add next char, represents the length.
 */
void print_buff(char buffer[], int *b_index)
{
	if (*b_index > 0)
		write(1, &buffer[0], *b_index);

	*b_index = 0;
}

