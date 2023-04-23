#include "main.h"

/**
 * print_HEX - prints an unsigned int in upper hexadecimal notation
 *
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of chars printed
 */

int print_HEX(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexadecimal(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
