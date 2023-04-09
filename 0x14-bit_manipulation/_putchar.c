#include "main.h"
#include <unistd.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to be written
 *
 * Return: 1 on success, -1 on error
 */

int _putchar(char c)
{
	int status = write(1, &c, 1);

	if (status == -1)
	{
		return (status);
	}

	return (1);
}

