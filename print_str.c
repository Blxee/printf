#include "main.h"

/**
 * print_str - prints a string to stdout
 *
 * @str: the string to print
 *
 * Return:
 *	number of printed characters on success
 *	-1 on failure
 */
int print_str(char *str)
{
	int i, total_chars_printed, chars_printed;

	if (str == NULL)
		str = "(null)";

	total_chars_printed = 0;
	for (i = 0; str[i]; i++)
	{
		chars_printed = _putchar(str[i]);
		if (chars_printed == -1)
			return (-1);
		total_chars_printed += chars_printed;
	}
	return (total_chars_printed);
}
