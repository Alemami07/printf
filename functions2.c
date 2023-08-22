#include "main.h"

/****************** PRINT POINTER ******************/
/**
 * print_pointer - Prints the value of a pointer variable
 * @list: Argument list
 * @width: width
 * @size: Size specifier
 * @buffer: Array of buffer to handle print
 * @flags: finds active flags
 * @precision: Precision specifier
 * Return: Number of chars printed.
 */
int print_pointer(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int index = BUFFER_SIZE - 2, length = 2; /*length=2, for '0x' */
	int padd_start = 1;
	unsigned long num_pl;
	char map_to[] = "0123456789abcdef";
	void *place = va_arg(list, void *);

	UNUSED(width);
	UNUSED(size);

	if (place == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER_SIZE - 1] = '\0';
	UNUSED(precision);

	num_pl = (unsigned long)place;

	while (num_pl > 0)
	{
		buffer[index--] = map_to[num_pl % 16];
		num_pl /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	index++;

	/*return value (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, index, length,
		width, flags, padd, extra_c, padd_start));
}

/************************* PRINT NON PRINTABLE *************************/
/**
 * print_un_printable - Prints ascii codes in hexa of non printable chars
 * @precision: Precision specifier
 * @buffer: Array of buffer to handle print
 * @flags:  finds active flags
 * @width: finds width
 * @list: Argument list
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_un_printable(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = 0, off_set = 0;
	char *str = va_arg(list, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[p] != '\0')
	{
		if (is_printable(str[p]))
			buffer[p + off_set] = str[p];
		else
			off_set += append_hexa_code(str[p], buffer, p + off_set);

		p++;
	}

	buffer[p + off_set] = '\0';

	return (write(1, buffer, p + off_set));
}

/************************* PRINT REVERSE *************************/
/**
 * print_rev - Prints reverse string.
 * @list: Arguments list
 * @buffer: Array of buffer to handle print
 * @size: Size specifier
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * Return: Numbers of chars printed
 */

int print_rev(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int p, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(list, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (p = 0; str[p]; p++)
	{
	for (p = p - 1; p >= 0; p--)
	{
		char g = str[p];

		write(1, &g, 1);
		count++;
	}
	}
	return (count);
}
/************************* PRINT A STRING IN ROT13 *************************/
/**
 * print_rot13 - Print a string in rot13.
 * @size: Size specifier
 * @flags:  finds  active
 * @list: Arguments list
 * @buffer: Array of buffer to handle print
 * @width: calculate width
 * @precision: Precision specifier
 * Return: Numbers of chars printed
 */
int print_rot13(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char c;
	char *str;
	unsigned int p, q;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (p = 0; str[p]; p++)
	{
		for (q = 0; in[q]; q++)
		{
			if (in[q] == str[q])
			{
				c = out[q];
				write(1, &c, 1);
				count++;
				break;
			}
		}
		if (!in[q])
		{
			c = str[p];
			write(1, &c, 1);
			count++;
		}
	}
	return (count);
}
