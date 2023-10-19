#include "main.h"
#include <stdarg.h>
#include <unistd.h>

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

	va_start(args, format);
	while (*format)
	{
		if (*format == '%' && format[1])
		{
			format++;
			if (*format == 'c')
			{
				char c = (char)va_arg(args, int);

				count += write(1, &c, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(args, char *);

				if (!str)
					str = "(null)";
				while (*str)
					count += write(1, str++, 1);
			}
			else if (*format == '%')
				count += write(1, "%", 1);
			else
				count += write(1, format - 1, 2);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (count);
}
