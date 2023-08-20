#include "main.h"

/**
 * _printf - prints results according to format
 * @format: format of the input
 *
 * Return: return the number of characters printed
 */
int _printf(const char *format, ...)
{
	int ch_count;
	const char *ptr;
	va_list args;

	ptr = format;
	va_start(args, format);

	ptr = format;
	ch_count = 0;
	if (format == NULL)
		return (-1);
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == 'c')
			{
				char c = va_arg(args, int);
				putchar(c);
				ch_count++;
			}
			else if (*ptr == 's')
			{
				char *s = va_arg(args, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					ch_count++;
				}
			}
			else if (*ptr == '%')
			{
				putchar('%');
				ch_count++;
			}
		}
		else
		{
			putchar(*ptr);
			ch_count++;
		}
		ptr++;
	}

	va_end(args);
	return (ch_count);
}
