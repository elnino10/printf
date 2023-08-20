#include "main.h"

/**
 * get_width - gets the print width
 * @format: Formatted string of arguments
 * @a: Arguments list
 * @args: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *a, va_list args)
{
	int index;
	int width = 0;

	for (index = *a + 1; format[index] != '\0'; index++)
	{
		if (is_digit(format[index]))
		{
			width *= 10;
			width += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*a = index - 1;
	return (width);
}

