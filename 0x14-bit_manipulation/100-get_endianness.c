#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Return: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int num = 1;
	char *endian_check = (char *)&num;

	/* If the first byte of num is 1 its little endian */
	if (*endian_check == 1)
		return (1);
	else
		return (0);
}
