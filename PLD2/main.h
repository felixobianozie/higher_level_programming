#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int _printf(const char *format, ...);
int (*check_specifier(const char*))(va_list);

/**
 * struct func - struct for specifier to printer
 * @t: character to compare
 * @f: function to handle printing
 */
struct func {
	char *t;
	int (*f)(va_list);
};
typedef struct func func_t;

int print_char(va_list);
int print_str(va_list);
int print_cent(va_list);

#endif
