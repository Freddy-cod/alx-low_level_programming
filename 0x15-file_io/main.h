#ifndef MAIN_H
#define MAIN_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

/* Function prototypes */

/* Reads a text file and prints it to the POSIX standard output */
ssize_t read_textfile(const char *filename, size_t letters);

/* Creates a new file with the given text content */
int create_file(const char *filename, char *text_content);

/* Appends text content to an existing file */
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */

