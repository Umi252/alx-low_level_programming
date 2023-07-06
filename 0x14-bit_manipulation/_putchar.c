#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes the character c to stdout
 * @c:The character to print
 *
 * Return: On success, returns the number of bytes written.
 *         On error, returns -1 and sets errno appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

