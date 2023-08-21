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
	const int FLAG_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};
	const char FLAG_CHAR[] = {'-', '+', '0', '#', ' ', '\0'};
	int flag = 0;

	for (index = *a + 1; format[index] != '\0'; index++)
	{
		for (i = 0; FLAG_CHAR[i] != '\0'; i++)
			if (format[index] == FLAG_CHAR[i])
			{
				flag |= FLAG_ARR[i];
				break;
			}
		if (FLAG_CHAR[i] == 0)
			break;
	}
	*a = index - 1;
	return (flag);
}


