#include "main.h"
#include <stdarg.h>
#include <string.h>
/**
 * _printf - printf function
 * @format: format
 * Return: 0 for success or -1 for error
 */
int _printf(const char *format, ...)
{
	int i;
	char x;
	char *y;

	va_list arg;

	va_start(arg, format);
	if (format == NULL)
	{
		return (-1);
	}
	for (i = 0; format[i]; i++)
	{
		if (format[i] == '%' && format[i + 1] == 'c')
		{
			x = va_arg(arg, int);
			_putchar(x);
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == 's')
		{
			y = va_arg(arg, char*);
			while (*y)
			{
				_putchar(*y);
				y++;
			}
			i++;
		}
		else if (format[i] == '%' && format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		else
		{
			_putchar(format[i]);
		}
	}
	return (0);
}
