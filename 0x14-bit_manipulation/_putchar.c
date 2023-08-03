#include <unistd.h>
#include "main.h"

/**
 * _putchar - puts a character to the standard output.
 * @c: The character to be printed.
 *
 * Return: 1 on success. -1 on error, errno is set appropriately.
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}
