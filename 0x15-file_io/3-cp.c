#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_buffer - Allocate memory for a buffer of 1024 bytes.
 * @file: The name of the file for which the buffer is allocated.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Unable to allocate buffer for %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Close file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int close_status;

	close_status = close(fd);

	if (close_status == -1)
	{
		dprintf(STDERR_FILENO, "Error: Unable to close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copies the contents of one file to another.
 * @argc: number of args.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: Exit with code 97 if the argument count is incorrect.
 * Exit with code 98 if file_from does not exist or cannot be read.
 * Exit with code 99 if file_to cannot be created or written to.
 * Exit with code 100 if file_to or file_from cannot be closed.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to, bytes_read, bytes_written;
	char *buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	fd_from = open(argv[1], O_RDONLY);
	bytes_read = read(fd_from, buffer, 1024);
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do {
		if (fd_from == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Unable to read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		bytes_written = write(fd_to, buffer, bytes_read);
		if (fd_to == -1 || bytes_written == -1)
		{
			dprintf(STDERR_FILENO,
				"Error: Unable to write to %s\n", argv[2]);
			free(buffer);
			exit(99);
		}

		bytes_read = read(fd_from, buffer, 1024);
		fd_to = open(argv[2], O_WRONLY | O_APPEND);

	} while (bytes_read > 0);

	free(buffer);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
