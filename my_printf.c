#include "main.h"
#include <stdarg.h>

/**
 * _printf - print to stdoutput format...
 *
 * @format: format specifier
 *Return: number of byte printed
 */
int _printf(const char *format, ...)
{
	unsigned int i, count = 0;

	va_list list_of_args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
	{
		return (1);
	}
	va_start(list_of_args, format);

	for (i = 0; (format[i]); i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			_putchar(va_arg(list_of_args, int));
			count++;
		}
		else if (format[i + 1] == 's')
		{
			int s_count = _putss(va_arg(list_of_args, char *));
				i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
		}
		count += 1;
	}
	va_end(list_of_args);
	{
	return (count);
	}
}
