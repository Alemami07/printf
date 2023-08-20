#include "main.h"
/**
 *print_string - prints a string
 *@str: string to be printed
 *Return: number of characters printed
 */
int print_string(char *str)
{
	int _strlen;

	_strlen = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		_strlen += 1;
		str++;
	}
	return (_strlen);
}
