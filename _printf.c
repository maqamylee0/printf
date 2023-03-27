#include "main.h"

/**
 * _printf - prints formated output
 * @format: pointer to string
 *
 * Return: number of things printed
 */
int _printf(const char *format, ...)
{
	int i = 0, temp = 0, count = 0;
	va_list args;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);

	va_start(args, format);

	/* prints each character of string */
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
		{
			return (-1);
		}
		if (format[i] != '%' && format[i + 1] != '\0')
		{
			temp = write(1, &format[i], 1);
			count += temp;
			i++;
			continue;
		}
		if (format[i] == '%')
		{
			f = check_specifier(&format[i + 1]);
			if (f != NULL)
			{
				temp = f(args);
				count = count + temp;
				i = i + 2;
			}
			else
			{
				temp = write(1, &format[i + 1], 1);
				count = count + temp;
				i = i + 2;
				continue;
			}
		}
	}
	va_end(args);
	return (count);
}
