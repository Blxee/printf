#include "main.h"

/**
 * print_chr - prints a char
 *
 * @types: list a of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of chars printed
 */

int print_chr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
