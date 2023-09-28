#ifndef MAIN_H
#define MAIN_H

/* Function that converts a binary number to an unsigned int. */
unsigned int binary_to_uint(const char *b);

/* Function that prints the binary representation of an unsigned long int. */
void print_binary(unsigned long int n);

/* Function that retrieves the value of a bit at a given index. */
int get_bit(unsigned long int n, unsigned int index);

/* Function that sets the value of a bit to 1 at a given index. */
int set_bit(unsigned long int *n, unsigned int index);

/* Function that sets the value of a bit to 0 at a given index. */
int clear_bit(unsigned long int *n, unsigned int index);

/* Function that calculates the number of bits to flip */
unsigned int flip_bits(unsigned long int n, unsigned long int m);

/* Function that converts a string to an integer. */
int _atoi(const char *s);

/* Function that writes a character to the standard output (stdout). */
int _putchar(char c);

/* Function that checks the endianness of the system. */
int get_endianness(void);

#endif /* MAIN_H */
