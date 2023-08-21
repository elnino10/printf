#include "main.h"

/**
 * is_digit - checks if a char is a digit
 * @ch: Char to be checked
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);

	return (0);
}

/**
 * convert_num_size - Converts a number to its specified size
 * @num: Number to be converted
 * @size: Size indication of type to be converted.
 *
 * Return: Converted value of num
 */
long int convert_num_size(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_unsigned - Converts a number to specific size
 * @num: Number to be converted
 * @size: Indication of conversion type
 *
 * Return: Converted value of num
 */
long int convert_unsigned(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}

