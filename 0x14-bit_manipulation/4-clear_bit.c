#include "main.h"

/**
 * clear_bit - set the value to 0
 * @n: pointer
 * @index: clear bit a this index
 *
 * Return: 1 for success and -1 for failure
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index > 63)
		return (-1);

	*n = (~(1UL << index) & *n);
	return (1);
}
