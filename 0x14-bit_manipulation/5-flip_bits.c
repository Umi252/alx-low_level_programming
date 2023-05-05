#include "main.h"

/**
 * flip_bits - Counts the number of bits that need to be flipped to get from
 *             one number to another.
 *
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits that need to be flipped.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor_result = n ^ m;
	unsigned int flip_count = 0;

	for (int i = 63; i >= 0; i--)
	{
		unsigned long int current_bit = (xor_result >> i) & 1;

		if (current_bit == 1)
			flip_count++;
	}

	return (flip_count);
}
