#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function that prints formatted output.
 * @format: Format string containing format specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i;
	unsigned int s_count;
	unsigned int count = 0;

	va_start(args, format);

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
		}
		else if (format[i] == '%' && format[i + 1] == 'c')
		{
			char c = (char)va_arg(args, int);

			_putchar(c);
			i++;
		}
		else if (format[i + 1] == 's')
		{
			const char *str = va_arg(args, const char*);

			s_count = _putss(str);
			i++;
			count += (s_count - 1);
		}
		else if (format[i + 1] == '%')
		{
			_putchar('%');
			i++;
		}
		count++;
	}
	va_end(args);
	return (count);
}
