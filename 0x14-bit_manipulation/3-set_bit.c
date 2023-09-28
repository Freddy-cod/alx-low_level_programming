/**
 * set_bit - Sets the value of a bit to 1 at index.
 * @n: A pointer to the unsigned long integer .
 * @index: The index of the bit to set, starting from 0.
 *
 * Return: 1 if the bit was successfully set, or -1.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	/* Check if index is greater than the num of bits */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Set the bit at the specified index to 1 */
	*n = *n | mask;

	return (1);
}
