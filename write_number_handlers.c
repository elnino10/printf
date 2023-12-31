#include "main.h"

/**
 * write_number_handler - Handles printing
 * @is_negative: Lista of arguments
 * @ind: char types
 * @buffer: Buffer array
 * @flag:  Checks for active flags
 * @width: get width.
 * @prec: precision
 * @size: Size specification
 *
 * Return: Number of chars printed.
 */
int write_number_handler(int is_negative, int ind, char buffer[],
		int flag, int width, int prec, int size)
{
	int length = BUFF_SIZE - ind - 1;
	char pad = ' ', extra_char = 0;

	VOID(size);
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (is_negative)
		extra_char = '-';
	else if (flag & F_PLUS)
		extra_char = '+';
	else if (flag & F_SPACE)
		extra_char = ' ';

	return (write_num(ind, buffer, flag, width, prec,
				length, pad, extra_char));
}

/**
 * write_num - Write with bufffer
 * @ind: starting index on buffer
 * @buffer: Buffer
 * @flag: Flag
 * @width: width
 * @prec: Precision
 * @length: Number length
 * @pad: Padding character
 * @extra_char: Extra character
 *
 * Return: Count of printed chars.
 */
int write_num(int ind, char buffer[],
		int flag, int width, int prec,
		int length, char pad, char extra_char)
{
	int i, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0); /* printf(".0d", 0)  no char is printed */
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = pad = ' '; /* width is displayed with padding ' ' */
	if (prec > 0 && prec < length)
		pad = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (extra_char != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flag & F_MINUS && pad == ' ')/* Asign extra char to left of buffer */
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flag & F_MINUS) && pad == ' ')/* extra char to left of buff */
		{
			if (extra_char)
				buffer[--ind] = extra_char;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flag & F_MINUS) && pad == '0')/* extra char to left of padding */
		{
			if (extra_char)
				buffer[--pad_start] = extra_char;
			return (write(1, &buffer[pad_start], i - pad_start) +
					write(1, &buffer[ind], length - (1 - pad_start)));
		}
	}
	if (extra_char)
		buffer[--ind] = extra_char;
	return (write(1, &buffer[ind], length));
}

/**
 * write_unsigned - Writes unsigned integer
 * @negative: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @buffer: Array of chars
 * @flag: Flag specifiers
 * @width: Width specifier
 * @prec: Precision
 * @size: Size specification
 *
 * Return: written character
 */
int write_unsigned(int negative, int index,
		char buffer[],
		int flag, int width, int prec, int size)
{
	/* The number is stored from right and starts at i */
	char pad = ' ';
	int len = BUFF_SIZE - index - 1, i = 0;

	VOID(negative);
	VOID(size);

	if (prec == 0 && index == BUFF_SIZE - 2 && buffer[index] == '0')
		return (0);
	if (prec > 0 && prec < len)
		pad = ' ';

	while (prec > len)
	{
		buffer[--index] = '0';
		len++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (width > len)
	{
		for (i = 0; i < width - len; i++)
			buffer[i] = pad;

		buffer[i] = '\0';
		if (flag & F_MINUS) /* Asign extra character to buffer left*/
		{
			return (write(1, &buffer[index], len) + write(1, &buffer[0], i));
		}
		else /* Asign extra char to padding left*/
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[index], len));
		}
	}

	return (write(1, &buffer[index], len));
}

