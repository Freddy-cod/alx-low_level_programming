/**
 * get_bit - ouputs the value of a bit at index.
 * @n: The number to extract the bit from.
 * @index: The index of the bit to retrieve.
 *
 * Return: The value of the bit at the specified index.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	/* Check if index is greater than the number of bits in 'n' */
	if (index >= (sizeof(unsigned long int) * 8))
		return (-1);

	/* Check if the bit at the specified index is 1 or 0 */
	if (n & mask)
		return (1);
	else
		return (0);
}
