#include "main.h"

/**
 * print_hex - prints an unsigned number in hexadecimal notation
 *
 * @types: lista of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: precision specification
 * @size: size specifier
 *
 * Return: number of chars printed
 */

int print_hex(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexadecimal(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}
