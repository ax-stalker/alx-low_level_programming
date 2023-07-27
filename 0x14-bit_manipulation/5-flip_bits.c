#include "main.h"

/**
 * flip_bits - calcs the number of bits to change
 *
 * @n: first no
 * @m: second no
 *
 * Return: number of changed bits
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, calc = 0;
	unsigned long int now;
	unsigned long int exclusive = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		now = exclusive >> i;
		if (now & 1)
			calc++;
	}

	return (calc);
}
