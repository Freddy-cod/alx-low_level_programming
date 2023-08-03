#include "main.h"

/**
 * clear_bit - Sets the value of a bit to 0 at index.
 * @n: A pointer to the unsigned long integer
 * @index: The index of the bit to clear, starting from 0.
 *
 * Return: 1 if the bit was successfully cleared or -1.
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	/* Check if index is greater than the num of bits */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Clear the bit at the specified index to 0 */
	*n = *n & ~mask;

	return (1);
}
