#include "main.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *_printf - custm printf function
 *@format: format to be printed
 *Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int q, printed = 0, len_str, strings = 0;
	char *s, c;

	va_start(args, format);
		if (!(format))
			return (-1);
		for (q = 0; format[q] != '\0'; q++)
		{
			if (format[q] != '%')
			{
				_putchar(format[q]);
				printed++;
			}
			if (format[q] == '%')
			{
			if (format[q] == '%' && format[q + 1] == '\0')
				return (-1);
			else if (format[q] == '%' && format[q + 1] == 's')
			{
				s = va_arg(args, char *);
				len_str = print_string(s);
				strings += len_str;
				++q;
			}
			else if (format[q] == '%' && format[q + 1] == 'c')
			{
				c = va_arg(args, int);
				_putchar(c);
				printed++;
				++q;
			}
			else if (format[q] == '%' && format[q + 1] == '%')
			{
				pprint();
				printed++;
				++q;
			}
			else if (format[q] == '%' && format[q + 1])
			{
				_putchar(format[q]);
				printed += 1;
			}
			}
		}
		printed += strings;
	va_end(args);
	return (printed);
}
