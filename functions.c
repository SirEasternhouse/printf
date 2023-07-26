#include "main.h"
/**
 *int_to_str - covertiing an integer to a string
 *@str: string to print
 *@num: number to convert to str
 *
 *
 *Return: converted integer to string
 */
int int_to_str(char *str, int num)
{
	int len = 0;
	int is_negative = 0;
	char temp_str[20];
	int temp_len = 0;

	/*handling of negative numbers*/
	if (num < 0)
	{
		is_negative = 1;
		num = -num;
	}
	/*Case for zero*/
	if (num == 0)
	{
		str[len++] = '0';
	}
	/*reverse order numbering */
	while (num > 0)
	{
		temp_str[temp_len++] = '0' + (num % 10);
		num /= 10;
	}

	/*addition of negative sign if necessary*/
	if (is_negative)
	{
		temp_str[len++] = '-';
	}
	/*revesal of string to get correct order*/
	while (temp_len > 0)
	{
		str[len++] = temp_str[--temp_len];
	}
	return (len);
}
