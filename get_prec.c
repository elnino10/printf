#include "main.h"

/**
 * get_precision - gets the precision for printing
 * @format: Formatted string
 * @a: Arguments
 * @args: list of arguments.
 *
 * Return: Precision.
 */
int get_prec(const char *format, int *a, va_list args)
{
	int index = *a + 1;
	int prec = -1;

	if (format[index] != '.')
		return (prec);
	prec = 0;
	for (index += 1; format[index] != '\0'; index++)
	{
		if (is_digit(format[index]))
		{
			prec *= 10;
			prec += format[index] - '0';
		}
		else if (format[index] == '*')
		{
			index++;
			prec = va_arg(args, int);
			break;
		}
		else
			break;
	}
	*a = index - 1;
	return (prec);
}

