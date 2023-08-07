#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Copy the contents of one file to another.
 * @ac: The number of arguments supplied to the program.
 * @av: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exit with code 97 if the argument count is incorrect.
 * Exit with code 98 if file_from does not exist or cannot be read.
 * Exit with code 99 if file_to cannot be created or written to.
 * Exit with code 100 if file_to or file_from cannot be closed.
 */
int main(int ac, char *av[])
{
	int fd_from, fd_to, rd_stat, wr_stat;
	mode_t perm = S_IRUSR | S_IWUSR | S_IWGRP | S_IRGRP | S_IROTH;
	char buffer[BUFSIZE];

	if (ac != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, perm);
	if (fd_to == -1)
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
	rd_stat = 1;
	while (rd_stat)
	{
		rd_stat = read(fd_from, buffer, BUFSIZE);
		if (rd_stat == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]), exit(98);
		if (rd_stat > 0)
		{
			wr_stat = write(fd_to, buffer, rd_stat);
			if (wr_stat != rd_stat || wr_stat == -1)
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]), exit(99);
		}
	}
	if (close(fd_from) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from), exit(100);
	if (close(fd_to) == -1)
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to), exit(100);
	return (0);
}
