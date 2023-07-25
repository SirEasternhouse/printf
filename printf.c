/* possible libraries we need*/
#include "main.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - print formated characters or strings to the standard output
 * @format: the string or character to print
 *
 *Return:the printed string or characters
 *
 */
int _printf(const char *format, ...) /*start of the function*/
{
	int num_chars_written = 0;

	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++; /*move past '%'*/
			/*Handling  of format specifiers */
			switch (*format)
			{
				case 'c':
					{
						char ch = va_arg(args, int);

						write(STDOUT_FILENO, &ch, 1);
						num_chars_written++;
						break;
					}
				case 's':
					{
						char *str = va_arg(args, char *);

						while (*str)
						{
							write(STDOUT_FILENO, str, 1);
							str++;
							num_chars_written++;
						}
						break;
					}
				case '%':
					{
						write(STDOUT_FILENO, "%", 1);
						num_chars_written++;
						break;
					}
				default:
					/*if the format specifier is not recognized, print as is*/
					write(STDOUT_FILENO, "%", 1);
					write(STDOUT_FILENO, format, 1);
					num_chars_written += 2;
					break;
			}
		}
		else
		{
			write(STDOUT_FILENO, format, 1);
			num_chars_written++;
		}
		format++;
	}
	va_end(args);
	return (num_chars_written);
}
