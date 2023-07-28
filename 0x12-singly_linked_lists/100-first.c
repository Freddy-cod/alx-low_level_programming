#include <stdio.h>

/* Declare the first function wit */
void first(void) __attribute__ ((constructor));

/**
 * first - Prints a sentence before the main function is executed.
 * This function is executed automatically before the main function.
 * It prints two lines of text to the standard output.
 */
void first(void)
{
	/* Print the first line of the sentence */
	printf("You're beat! and yet, you must allow,\n");

	/* Print the second line of the sentence */
	printf("I bore my house upon my back!\n");
}

