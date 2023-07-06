#include <stdio.h>
#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Description: Determines whether the system uses big endian or little endian
 * byte order by examining the memory representation of an unsigned int.
 *
 * Return: 0 if big endian, 1 if little endian.
 */

int main(void)
{
	int n;

	n = get_endianness();
	if (n != 0)
	{
		printf("Little Endian\n");
	}
	else
	{
		printf("Big Endian\n");
	}
	return (0);
}
