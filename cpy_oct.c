#include "main.h"

/**
 * cpy_oct - handles octaval
 * @args: argument list
 * @buff: buffer
 * @buff_loc: buffer position pointer
 * Return: number of chars printed
 */
int cpy_oct(va_list args, char *buff, unsigned long int *buff_loc)
{

	int count, len = 0;
	unsigned int num_1, num = va_arg(args, int);
	char *str;
	int i;

	num_1 = num;
	if (num == 0)
	{
		buff[*buff_loc] = '0';
		*buff_loc = *buff_loc + 1;
		buff_check(buff, buff_loc);
		return (1);
	}
	for ( ; num_1 != 0; num_1 /= 8)
		len++;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (-1);

	count = len;

	for (i = len - 1; i >= 0; i--)
	{
		int rem = num % 8;

		num = num / 8;
		str[i] = rem + '0';
	}

	for (i = 0; i < len; i++)
	{
		buff[*buff_loc] = str[i];
		*buff_loc = *buff_loc + 1;
		buff_check(buff, buff_loc);
	}
	free(str);
	return (count);
}
