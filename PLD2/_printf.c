#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - prints a string in a formatted way
 * @format: string to print (char *)
 * @...: variadic parameters (unknown)
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int value = 0;
	va_list args;
	va_start(args, format);
	int (*f)(va_list);

	/*Prevent parsing a null pointer*/
	if (format == NULL)
		return (-1);
	
	/*Print each character of string*/
	while (format[i])
	{	
		/*Print all non % characters*/
		if (format[i] != '%')
		{
			value = write(1,&format[i],1);
			count = count + value;
			i++;
			continue;
		}

		/*Handles specifiers*/
		if (format[i] == '%')
		{
			f = check_specifier(&format[i + 1]);
			if (f != NULL)
			{
				value = f(args);
				count = count + value;
				i = i + 2;
				continue;
			}

			/*When specifier does not match formal types*/
			if (format[i + 1] == '\0')
				break;

			if (format[i + 1] != '\0')
			{
				value = write(1,&format[i],1);
				count = count + value;
				i = i + 2;
				continue;
			}
		}
	}

	return (count);
}
