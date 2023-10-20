#include "main.h"
#include <stdarg.h>
/**
 * _printf - Custom printf function that handles 'c', 's', 'd', and 'i' specifiers.
 * @format: Format string containing format specifiers.
 *
 * Return: Number of characters printed (excluding null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i, count = 0;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (1);
	va_start(args, format);
	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char c = (char)va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (format[i] == 's')
			{
				const char *str = va_arg(args, const char *);

				count += _putss(str);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				int num = va_arg(args, int);

				count += _putint(num);
			}
			else if (format[i] == '%')
			{
				_putchar('%');
				count++;
			}
		}
	}
	va_end(args);
	return (count);
}
