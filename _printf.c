#include "main.h"
/**
 * _printf - prints formated output
 * @format: pointer to string
 *
 * Return: number of things printed
 */
int _printf(const char *format, ...)
{
	int i = 0;
	int temp = 0;
	int count = 0;
	va_list args;
	int (*f)(va_list);
	va_start(args, format);
	/* ensures NULL pointer isnt parsed */
	if (format == NULL)
		return (-1);
	
	/* prints each character of string */
	while (format[i])
	{
		if (format[i] != '%')
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
				continue;
			}
			if (format[i + 1] == '\0')
			{
				break;
			}
			if (format[i + 1] != '\0')
			{
				temp = write(1, &format[i + 1], 1);
				count += temp;
				i = i + 2;
				continue;
			}
		}
	}
	va_end(args);
	return (count);
}
