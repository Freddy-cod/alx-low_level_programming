/**
 * binary_to_uint - transform a binary number represented
 * as a string to an unsigned int.
 * @binary: A pointer to the string containing the binary number.
 *
 * Return: The converted unsigned int number
 * or 0 if not a valid binar.
 */
unsigned int binary_to_uint(const char *binary)
{
	int index;
	unsigned int decimal_value = 0;

	if (!binary)
		return (0);

	/* Loop through each character  */
	for (index = 0; binary[index]; index++)
	{
		/* Check if the character is a valid binary digit */
		if (binary[index] < '0' || binary[index] > '1')
			return (0);

		/* Convert the binary digit */
		decimal_value = 2 * decimal_value + (binary[index] - '0');
	}

	/* Return the final converted decimal value */
	return (decimal_value);
}
