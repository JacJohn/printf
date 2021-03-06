#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct convert - defines a structure for symbols and functions
 * @sym: The operator
 * @f: The function associated
 */
struct convert
{
	char *sym;
	int (*f)(va_list);
};
typedef struct convert conver_t;

/*Main functions*/
int _printf(const char *format, ...);
int print_char(va_list);
int print_string(va_list);
int print_integer(va_list);

#endif
