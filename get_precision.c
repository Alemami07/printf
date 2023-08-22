#include "main.h"

/**
 * get_precision - gets the precision for printing
 * @p: Aguments to be printed
 * @format: Formatted string to print the argument
 * @args: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *p, va_list args)
{
	int curr_p = *p + 1;
	int precision = -1;

	if (format[curr_p] != '.')
		return (precision);

	precision = 0;

	for (curr_p += 1; format[curr_p] != '\0'; curr_p++)
	{
		if (is_digit(format[curr_p]))
		{
			precision *= 10;
			precision += format[curr_p] - '0';
		}
		else if (format[curr_p] == '*')
		{
			curr_p++;
			precision = va_arg(args, int);
			break;
		}
		else
			break;
	}

	*p = curr_p - 1;

	return (precision);
}
