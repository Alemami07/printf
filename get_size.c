#include "main.h"

/**
 * get_size - gets the size of the argument
 * @p: number of arguments to be printed
 * @format: formatted string
 *
 * Return: precise value
 */
int get_size(const char *format, int *p)
{
	int curr_p = *p + 1;
	int size = 0;

	if (format[curr_p] == 'l')
		size = S_LONG;
	else if (format[curr_p] == 'h')
		size = S_SHORT;

	if (size == 0)
		*p = curr_p - 1;
	else
		*p = curr_p;

	return (size);
}
