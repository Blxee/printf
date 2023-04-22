#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

#ifndef NULL
#define NULL ((void *)0)
#endif /* !NULL */

int _printf(const char *format, ...);
int print_fmt(char fmt, va_list lst);
int _putchar(char c);
int print_str(char *);

#endif /* !MAIN_H */
