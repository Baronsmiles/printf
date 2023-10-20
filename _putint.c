#include "main.h"

/**
 * _putint - Print an integer.
 * @n: The integer to print.
 *
 * Return: Number of digits printed.
 */
int _putint(int n)
{
	int count = 0;

	if (n < 0)
	{
		_putchar('-');
		count++;
		n = -n;
	}

	if (n / 10 != 0)
		count += _putint(n / 10);

	_putchar((char)(n % 10 + '0'));
	return (count + 1);
}
