#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - prints character from variadic parameters
 * @args: variadic arguments
 *
 * Return: number of characters printed on success
 * 	0 on failure.
 */

int print_char(va_list args)
{
	int count = 0;

	char c = (char)va_arg(args, int);
	
	if (c)
	{
		count = write(1, &c, 1);
		return (count);
	}

	return (0);
}
