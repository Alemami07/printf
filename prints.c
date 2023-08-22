#include "main.h"
/**
 * handle_print - Prints an argument according to its type
 * @flags: Calculates active flags
 * @args: arguments to be printed.
 * @index: indexes
 * @precision: Precision specifier
 * @buffer: Array of buffer to handle print.
 * @width: get width.
 * @fmt: Formatted string to print the arguments.
 * @size: Size specifier
 * Return: 1 or 2;
 */
int handle_print(const char *fmt, int *index, va_list args, char buffer[],
	int flags, int width, int precision, int size)
{
	int p, unknow_len = 0, chars = -1;
	fmt_t fmt_list[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_x},
		{'X', print_hex_upper}, {'p', print_pointer}, {'S', print_un_printable},
		{'r', print_rev}, {'R', print_rot13}, {'\0', NULL},
		{NULL, NULL}
	};
	for (p = 0; fmt_list[p].fmt != '\0'; p++)
		if (fmt[*index] == fmt_list[p].fmt)
			return (fmt_list[p].fn(args, buffer, flags, width, precision, size));

	if (fmt_list[p].fmt == '\0')
	{
		if (fmt[*index] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*index - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*index);
			while (fmt[*index] != ' ' && fmt[*index] != '%')
				--(*index);
			if (fmt[*index] == ' ')
				--(*index);
			return (1);
		}
		unknow_len += write(1, &fmt[*index], 1);
		return (unknow_len);
	}
	return (chars);
}
