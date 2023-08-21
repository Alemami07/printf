#include "main.h"
#include <stddef.h>
/**
 *print_string - prints a string
 *@str: string to be printed
 *Return: number of characters printed
 */
unsigned int print_string(char *str)
{
	char *err;
	unsigned int p;

	p = 0;
	if (str == NULL)
	{
		err = "(null)";
		while (err[p] != '\0')
		{
			_putchar(err[p]);
			p++;
		}
		return (p);
	}
	while (str[p] != '\0')
	{
		_putchar(str[p]);
		p++;
	}
	return (p);

}
