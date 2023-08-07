#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#define BUF_SIZE 1024

/**
 * main - Copies the content of a file to another file.
 * @argc: The number of arguments.
 * @argv: An array of strings containing the arguments.
 *
 * Return: On success, 0. On failure, exit with the specified codes.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t bytes_read, bytes_written;
	char buffer[BUF_SIZE];

	/* Check if the number of arguments is correct */
	if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n"), exit(97);

	/* Open the source file for reading */
	file_from = open(argv[1], O_RDONLY);
	if (file_from == -1)
		dprintf(STDERR_FILENO, "Error:%s\n", argv[1]), exit(98);

	/* Open the destination file for writing */
	file_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (file_to == -1)
		dprintf(STDERR_FILENO, "Can't write to %s\n", argv[2]), exit(99);

	/* Copy content from source file to destination file */
	while ((bytes_read = read(file_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(file_to, buffer, bytes_read);
		if (bytes_written == -1)
			dprintf(STDERR_FILENO, "Can't write to %s\n", argv[2]), exit(99);
	}

	if (bytes_read == -1)
		dprintf(STDERR_FILENO, "Error: %s\n", argv[1]), exit(98);

	/* Close file descriptors */
	if (close(file_from) == -1)
		dprintf(STDERR_FILENO, "Can't close fd %d\n", file_from), exit(100);

	if (close(file_to) == -1)
		dprintf(STDERR_FILENO, "Can't close fd %d\n", file_to), exit(100);

	return (0);
}
