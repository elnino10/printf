#include "main.h"

/**
 * get_flag - Checks for active flags
 * @format: Formatted string in which to print the arguments
 * @a: parameter
 * 
 * Return: Flags
 */
int get_flag(const char *format, int *a)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int i, index;
	int flags = 0;
	const char FLAGS_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARRAR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (index = *a + 1; format[index] != '\0'; index++)
	{
		for (i = 0; FLAGS_CHAR[i] != '\0'; i++)
			if (format[index] == FLAGS_CHAR[i])
			{
				flags |= FLAGS_ARRAR[i];
				break;
			}
		if (FLAGS_CHAR[i] == 0)
			break;
	}
	*a = index - 1;
	return (flags);
}


