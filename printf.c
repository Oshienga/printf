#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

/**
 * _printf - Entry point
 * Description: 'program'
 * @format: format
 * Return: result
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char buffer[32], *str;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			if (*format == 'c')
			{
				buffer[0] = va_arg(args, int);
				count += write(1, buffer, 1);
			}
			else if (*format == 's')
			{
				str = va_arg(args, char*);
				if (!str)
					str = "(null)";
				while (*str)
					count += write(1, str++, 1);
			}
			else if (*format == '%')
				count += write(1, "%", 1);
			else if (*format == 'p' || *format == 'd')
			{
				if (*format == 'p')
					sprintf(buffer, "%p", va_arg(args, void*));
				else if (*format == 'd')
					sprintf(buffer, "%d", va_arg(args, int));
				count += write(1, buffer, strlen(buffer));
			}
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
