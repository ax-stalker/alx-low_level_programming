#include "main.h"

/**
 * get_bit - return the bit value
 * @n: search for this number
 * @index: index of the bit
 *
 * Return: bit value
 */
int get_bit(unsigned long int n, unsigned int index)
{
	int Bvalue;

	if (index > 63)
		return (-1);

	Bvalue = (n >> index) & 1;

	return (Bvalue);
}
