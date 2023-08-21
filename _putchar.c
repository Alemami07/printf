#include <unistd.h>
/**
 *_putchar - writes to stdout
 *
 *@c: character printed
 *Return: an int
 */
int _putchar(char c)
{
	if (!c)
	{
		_putchar(' ');
		return (0);
	}
	return (write(1, &c, 1));
}
