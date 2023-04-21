#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints formated string to stdout
 *
 * @format: a format string to use
 *
 * Return:
 *	number of printed characters on success
 *	-1 on failure
 */
int _printf(const char *format, ...)
{
	va_list lst;
	int i, chars_printed, total_chars_printed;

	va_start(lst, format);

	i = 0;
	total_chars_printed = 0;
	chars_printed = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			chars_printed = _putchar(format[i]);
			i++;
		}
		else
		{
			switch (format[i + 1])
			{
				case '%':
					chars_printed = _putchar('%');
					break;
				case 'c':
					chars_printed = _putchar(va_arg(lst, int));
					break;
				case 's':
					chars_printed = print_str(va_arg(lst, char *));
					break;
			}
			i += 2;
		}
		if (chars_printed == -1)
		{
			va_end(lst);
			return (-1);
		}
		total_chars_printed += chars_printed;
	}
	va_end(lst);
	return (total_chars_printed);
}
