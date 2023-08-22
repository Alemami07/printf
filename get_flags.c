#include "main.h"

/**
 * get_flags - Calculates the active flags
 * @p: a parameter.
 * @format: Formatted string to print the arguments
 * Return: Flags:
 */
int get_flags(const char *format, int *p)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int q, curr_p;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_p = *p + 1; format[curr_p] != '\0'; curr_p++)
	{
		for (q = 0; FLAGS_CH[q] != '\0'; q++)
			if (format[curr_p] == FLAGS_CH[q])
			{
				flags |= FLAGS_ARR[q];
				break;
			}

		if (FLAGS_CH[q] == 0)
			break;
	}

	*p = curr_p - 1;

	return (flags);
}
