#include "main.h"

/**
 * print_binary - outputs the binary equivalent of a decimal number
 * @n : variable
 */
void print_binary(unsigned long int n)
{
	int i, calc = 0;
	unsigned long int now;

	for (i = 63; i >= 0; i--)
	{
		now  = n >> i;

		if (now & 1)
		{
			_putchar('1');
			calc++;
		}
		else if (calc)
			_putchar('0');
	}
	if (!calc)
		_putchar('0');
}

