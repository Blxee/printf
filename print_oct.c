#include "main.h"

/**
 * print_oct - prints an unsigned number in octal notation
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

int print_oct(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_uint(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}