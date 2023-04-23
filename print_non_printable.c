#include "main.h"

/**
 * print_non_printable - prints ascii codes in hexa of non printable chars
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

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += add_hex_prefix(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}
