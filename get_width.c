#include "main.h"

/**
 * get_width - gets the width for printing
 * @p: arguments to be printed.
 * @format: Formatted string to print the arguments.
 * @args: list of arguments.
 *
 * Return: width.
 */
int get_width(const char *format, int *p, va_list args)
{
	int curr_p;
	int width = 0;

	for (curr_p = *p + 1; format[curr_p] != '\0'; curr_p++)
	{
		if (is_digit(format[curr_p]))
		{
			width *= 10;
			width += format[curr_p] - '0';
		}
		else if (format[curr_p] == '*')
		{
			curr_p++;
			width = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*p = curr_p - 1;

	return (width);
}
