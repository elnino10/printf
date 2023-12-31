#include "main.h"

/**
 * handle_write_ch - Prints a string
 * @c: char types.
 * @buffer: Buffer array to handle print
 * @flag:  checks active flags.
 * @width: get width.
 * @prec: precision
 * @size: Size
 *
 * Return: Number of chars printed.
 */
int handle_write_ch(char c, char buffer[],
	int flag, int width, int prec, int size)
{
	int i = 0;
	char pad = ' ';

	VOID(prec);
	VOID(size);

	if (flag & F_ZERO)
		pad = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFF_SIZE - i - 2] = pad;

		if (flag & F_MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFF_SIZE - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFF_SIZE - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}

