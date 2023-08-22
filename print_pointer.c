#include "main.h"

/**
 * print_pointer - Prints the address of variable
 * @args: Arguments list
 * @buffer: Buffer array
 * @flag:  Checks for active flag
 * @width: get width
 * @prec: Precision
 * @size: Size specification
 *
 * Return: write pointer value
 */
int print_pointer(va_list args, char buffer[],
		int flag, int width, int prec, int size)
{
	char extra_ch = 0, pad = ' ';
	unsigned long num_address;
	int index = BUFF_SIZE - 2, len = 2, pad_start = 1;
	char map[] = "0123456789abcdef";
	void *address = va_arg(args, void *);

	VOID(width);
	VOID(prec);
	VOID(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buffer[BUFF_SIZE - 1] = '\0';

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[index--] = map[num_address % 16];
		num_address /= 16;
		len++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (flag & F_PLUS)
		extra_ch = '+', len++;
	else if (flag & F_SPACE)
		extra_ch = ' ', len++;
	index++;

	return (write_pointer(buffer, index, len,
				width, flag, pad, extra_ch, pad_start));
}

/**
 * write_pointer - Write a memory address
 * @buffer: Buffer arrays
 * @index: Index from where number starts in buffer
 * @len: Length of number
 * @width: Width specifier
 * @flag: Checks for active flag
 * @pad: Char representing the padding
 * @extra_ch: Char representing extra char
 * @pad_start: Index at which padding should start
 *
 * Return: character to stdout
 */
int write_pointer(char buffer[], int index, int len,
		int width, int flag, char pad, char extra_ch, int pad_start)
{
	int i;

	if (width > len)
	{
		for (i = 3; i < width - len + 3; i++)
			buffer[i] = pad;
		buffer[i] = '\0';
		if (flag & F_MINUS && pad == ' ')/* Asign extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[index], len) + write(1, &buffer[3], i - 3));
		}
		else if (!(flag & F_MINUS) && pad == ' ')/* extra char to left of buffer */
		{
			buffer[--index] = 'x';
			buffer[--index] = '0';
			if (extra_ch)
				buffer[--index] = extra_ch;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[index], len));
		}
		else if (!(flag & F_MINUS) && pad == '0')/* extra char to left of pad */
		{
			if (extra_ch)
				buffer[--pad_start] = extra_ch;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[pad_start], i - pad_start) +
					write(1, &buffer[index], len - (1 - pad_start) - 2));
		}
	}
	buffer[--index] = 'x';
	buffer[--index] = '0';
	if (extra_ch)
		buffer[--index] = extra_ch;
	return (write(1, &buffer[index], BUFF_SIZE - index - 1));
}

