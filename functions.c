#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @width: Width
 * @list: List a of arguments
 * @size: Size specifier
 * @buffer: Array of buffer to handle print
 * @flags:  finds  active flags
 * @precision: Precision specifier
 * Return: Number of chars printed
 */
int print_char(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(list, int);

	return (handle_write(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @size: Size specifier
 * @list: Arguments list
 * @buffer: Array of buffer to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specifier
 * Return: Number of chars printed
 */
int print_string(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, p;
	char *str = va_arg(list, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (p = width - length; p > 0; p--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (p = width - length; p > 0; p--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @list: Arguments list
 * @flags:  get active flags
 * @size: Size specifier
 * @buffer: array of buffer to handle print
 * @width: get width.
 * @precision: Precision specifier
 * Return: Number of chars printed
 */
int print_percent(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(list);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @list: Arguments
 * @buffer: Buffer array
 * @flags:  finds active flags
 * @width: width.
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_int(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(list, long int);
	unsigned long int num;

	n = conv_size_number(n, size);

	if (n == 0)
		buffer[p--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[p--] = (num % 10) + '0';
		num /= 10;
	}

	p++;

	return (write_number(is_negative, p, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @list: Arguments list
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: width.
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Numbers of char printed.
 */
int print_binary(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int r, q, p, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	r = va_arg(list, unsigned int);
	q = 2147483648; /* (2 ^ 31) */
	a[0] = q / r;
	for (p = 1; p < 32; p++)
	{
		r /= 2;
		a[p] = (q / r) % 2;
	}
	for (p = 0, sum = 0, count = 0; p < 32; p++)
	{
		sum += a[p];
		if (sum || p == 31)
		{
			char g = '0' + a[p];

			write(1, &g, 1);
			count++;
		}
	}
	return (count);
}

