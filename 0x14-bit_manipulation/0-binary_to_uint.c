#include "main.h"
#include <stddef.h>

/**
 * binary_to_uint - converts a binary number to an unsigned int
 * @b: pointer to a string of 0 and 1 chars
 *
 * Return: converted number, or 0 if b is NULL or contains non-0/1 chars
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int ui = 0;
	int len = 0, base_two = 1;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
		len++;

	len--;

	while (len >= 0)

	{
		if (b[len] != '0' && b[len] != '1')
			return (0);

		if (b[len] & 1)
			ui += base_two;

		base_two *= 2;
		len--;
	}

	return (ui);
}

