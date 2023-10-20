#include "main.h"

/**
 * _putss - print string
 * 
 * @a: string
 * Return: number of byte
 */
int _putss(const char *a)
{
	int count = 0;

	if (a)
	{
		for (count = 0; a[count] != '\0'; count++)
		{
			_putchar(a[count]);
		}
	}
	return (count);
}
