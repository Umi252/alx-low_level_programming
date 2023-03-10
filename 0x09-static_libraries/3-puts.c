#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

/**
 * _puts - Prints a string of characters to the standard output
 *
 * @str: The string to be printed
 *
 * Return: None
 *
 * Description: The _puts function prints the string of characters pointed to
 * by @str to the standard output, followed by a newline character. If @str is
 * NULL, the function has no effect. If the string contains a null byte ('\0')
 * before the end of the characters that would be printed, the function prints
 * only the characters up to the null byte.
 */
void _puts(char *str);

#endif /* MAIN_H */

