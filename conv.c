#include "main.h"

/**
 * is_printable - finds out if a char is printable
 * @c: Char.
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @ascii_code: ASSCI CODE.
 * @p: Index to start appending from.
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int p)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is 2 digits long always */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[p++] = '\\';
	buffer[p++] = 'x';

	buffer[p++] = map_to[ascii_code / 16];
	buffer[p] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies whether a char is a digit
 * @c: Char to be evaluated
 *
 * Return: 1 if c is a digit, 0 otherwise
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * conv_size_number - Casts a number to the specified size
 * @size: Indicates the type to be casted.
 * @num: Number to be casted.
 *
 * Return: Casted value of num
 */
long int conv_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * conv_size_unsgnd - Casts a number to the specified size
 * @size: Indicates the type to be casted
 * @num: Number to be casted
 *
 * Return: Casted value of num
 */
long int conv_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
