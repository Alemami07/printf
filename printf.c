#include "main.h"

void print_buffer(char buffer[], int *buff_index);

/**
 * _printf - this is the printf function
 * @format: format.
 * Prepared by: cleve lihasi and Jemima Chinwi.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int p, printed = 0, chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list args;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (p = 0; format && format[p] != '\0'; p++)
	{
		if (format[p] != '%')
		{
			buffer[buff_index++] = format[p];
			if (buff_index == BUFFER_SIZE)
				print_buffer(buffer, &buff_index);
			/* write(1, &format[i], 1);*/
			chars++;
		}
		else
		{
			print_buffer(buffer, &buff_index);
			flags = get_flags(format, &p);
			width = get_width(format, &p, args);
			precision = get_precision(format, &p, args);
			size = get_size(format, &p);
			++p;
			printed = handle_print(format, &p, args, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			chars += printed;
		}
	}

	print_buffer(buffer, &buff_index);

	va_end(args);

	return (chars);
}

/**
 * print_buffer - This functions prints the content of buffer if present
 * @buffer: char arrays
 * @buff_index: this represents the buffer size
 */
void print_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}
