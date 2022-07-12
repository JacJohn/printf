#include <unistd.h>
#include "main.h"
#include <stdio.h>

/**
 * _printf - produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list list;
	unsigned int i = 0, buffer_pos = 0, count = 0;
	char *res_str, *aux, buffer[BUFFER_SIZE];

	if (!format || !format[0])
		return (-1);
	va_start(list, format);
	aux = malloc(sizeof(char) * 2);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			res_str = treat_format(format, &i, list);
			count += buffer_add(buffer, res_str, &buffer_pos);
			free(res_str);
		}
		else
		{
			aux[0] = format[i++];
			aux[1] = '\0';
			count += buffer_add(buffer, aux, &buffer_pos);
		}
	}
	count += buffer_print(buffer, buffer_pos);
	free(aux);
	va_end(list);
	if (!count)
		count = -1;
	return (count);
}
