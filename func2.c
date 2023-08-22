#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - this function prints an unsigned integer
 * @width: the width
 * @buffer: Buffer array to handle print
 * @list:  list the flags
 * @size: the size specifier
 * @flags: check active flags
 * @precision: Precision specification
 * Return: Number of chars printed.
 */
int print_unsigned(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int p = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = (num % 10) + '0';
		num /= 10;
	}

	p++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN OCTAL  ****************/
/**
 * print_octal - Prints number in octal notation
 * @list: List arguments
 * @buffer: Buffer array
 * @flags: active flags
 * @width: check width
 * @precision: checks Precision
 * @size: checks Size
 * Return: printed characters
 */
int print_octal(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{

	int p = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int in_num = num;

	UNUSED(width);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && in_num != 0)
		buffer[p--] = '0';

	p++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_x - Prints an unsigned number in hexadecimal notation
 * @size: checks Size
 * @buffer: handles print
 * @flags:  checks flags
 * @width: checks width
 * @list: List of arguments
 * @precision: Precision specifier
 * Return: Number of printed characters
 */
int print_x(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hex_upper - Printsunsigned number in upper hexadecimal notation
 * @flags: checks for active flags
 * @list: Lists of arguments
 * @width: calculate width
 * @precision: checks Precision
 * @size: checks Size
 * @buffer: Buffer array
 * Return: Number of printed characters
 */
int print_hex_upper(va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(list, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************** PRINT HEX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - Prints a hexadecimal number in lower or upper case
 * @list: Lists arguments
 * @flags:  Calculates active flags
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa(va_list list, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int p = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int in_num = num;

	UNUSED(width);

	num = conv_size_unsgnd(num, size);

	if (num == 0)
		buffer[p--] = '0';

	buffer[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[p--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && in_num != 0)
	{
		buffer[p--] = flag_ch;
		buffer[p--] = '0';
	}

	p++;

	return (write_unsgnd(0, p, buffer, flags, width, precision, size));
}
