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

	total_chars_printed = 0;
	chars_printed = 0;
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] != '%') /* if current char is no '%' then just print it */
		{
			chars_printed = _putchar(format[i]);
			i++;
		}
		else
		{
			chars_printed = print_fmt(format[i + 1], lst);
			i += 2; /* +2 to skip '%' and the format char */
		}
		if (chars_printed == -1) /* if print_fmt failed */
		{
			va_end(lst);
			return (-1);
		}
		total_chars_printed += chars_printed;
	}

	va_end(lst);
	return (total_chars_printed);
}

/**
 * print_fmt - helper function for _printf
 *
 * @fmt: a format character (ex: d, s, c..)
 * @lst: used to get the next variable argument of _printf
 *
 * Return:
 *	number of printed characters on success
 *	-1 on failure
 */
int print_fmt(char fmt, va_list lst)
{
	int chars_printed = 0;

	switch (fmt)
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
		/* handle each format char here */
	}

	if (chars_printed == -1)
		return (-1);
	else
		return (chars_printed);
}
