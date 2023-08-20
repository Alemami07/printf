#include <unistd.h>

/**
 * _putchar - writes the character c to output
 * @c: The character that will be printed
 * Return: On success 1
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

