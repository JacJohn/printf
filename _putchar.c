#include <unistd.h>
/**
 * _puthcar - writes c the character to stdout
 * @c: character to print
 * Return: 1
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
