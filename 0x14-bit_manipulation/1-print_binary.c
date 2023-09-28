#include "main.h"

/**
 * print_binary - Prints the binary representation
 * of a number.
 * @n: The number to print in binary.
 *
 * Description: This function takes an unsigned
 * long integer 'n' as input
 * and prints its binary representation to the
 * standard output
 * It avoids using arrays, malloc, %, or / operators
 * to achieve this.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1UL << (sizeof(unsigned long int) * 8 - 1);
	int found_one = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}

	while (mask)
	{
		if (n & mask)
		{
			_putchar('1');
			found_one = 1;
		}
		else if (found_one)
		{
			_putchar('0');
		}

		mask >>= 1;
	}
}
