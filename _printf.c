<<<<<<< HEAD
#include "main.h"
/**
 *_printf - printf
 *@format: const char pointer
 *Description: this functions implement some functions of printf
 *Return: num of characteres printed
 */
int _printf(const char *format, ...)
{
	const char *string;
	int cont = 0;
	va_list arg;

	if (!format)
		return (-1);

	va_start(arg, format);
	string = format;

	cont = loop_format(arg, string);

	va_end(arg);
	return (cont);
}
/**
 *loop_format - loop format
 *@arg: va_list arg
 *@string: pointer from format
 *Description: This function make loop tp string pointer
 *Return: num of characteres printed
 */
int loop_format(va_list arg, const char *string)
{
	int i = 0, flag = 0, cont_fm = 0, cont = 0, check_per = 0;

	while (i < _strlen((char *)string) && *string != '\0')
	{
		char aux = string[i];

		if (aux == '%')
		{
			i++, flag++;
			aux = string[i];
			if (aux == '\0' && _strlen((char *)string) == 1)
				return (-1);
			if (aux == '\0')
				return (cont);
			if (aux == '%')
			{
				flag++;
			} else
			{
				cont_fm = function_manager(aux, arg);
				if (cont_fm >= 0 && cont_fm != -1)
				{
					i++;
					aux = string[i];
					if (aux == '%')
						flag--;
					cont = cont + cont_fm;
				} else if (cont_fm == -1 && aux != '\n')
				{
					cont += _putchar('%');
				}
			}
		}
		check_per = check_percent(&flag, aux);
		cont += check_per;
		if (check_per == 0 && aux != '\0' && aux != '%')
			cont += _putchar(aux), i++;
		check_per = 0;
	}
	return (cont);
}
/**
 * check_percent - call function manager
 *@flag: value by reference
 *@aux: character
 *Description: This function print % pear
 *Return: 1 if % is printed
 */
int check_percent(int *flag, char aux)
{
	int tmp_flag;
	int cont = 0;

	tmp_flag = *flag;
	if (tmp_flag == 2 && aux == '%')
	{
		_putchar('%');
		tmp_flag = 0;
		cont = 1;
	}
	return (cont);
}

/**
 * call_function_manager - call function manager
 *@aux: character parameter
 *@arg: va_list arg
 *Description: This function call function manager
 *Return: num of characteres printed
 */

int call_function_manager(char aux, va_list arg)
{
	int cont = 0;

	cont = function_manager(aux, arg);
	return (cont);
=======
#include <unistd.h>
#include "main.h"
/**
 *_printf - takes in a string and prints different types of arguments for
 * an unspecified amount of arguments
 * @format: the initial string that tell us what is going to be printed
 * Return: the amount of times we write to stdout
 */
int _printf(const char *format, ...)
{
	int i, count;

	int (*f)(va_list);

	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);
	i = count = 0;

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			f = get_func(format[i + 1]);
			if (f == NULL)
				count += print_nan(format[i], format[i + 1]);
			else
				count += f(list);
			i++;
		}
		else
		{
			_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(list);
	return (count);
>>>>>>> a3519bf48f023c26f8aeff649427ad40b82a1558
}
