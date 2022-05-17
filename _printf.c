#include "main.h"
/**
 * _printf - produces output acording to a format
 * @foramt: format string containing the characters and the specifiers
 * Return: length of the formatted output string 
 */
int _printf(const char *format, ...)
{
int (*mfunc)(va_list, flags_t *);
const char *my_ptr;
va_list arguments;
flags_t flags = {0, 0, 0,};
register int i = 0;
va_start(arguments, format);
if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[i] == ' ' && !format[2])
return (-1);
for (my_ptr = format; *my_ptr; my_ptr++)
{
if (*my_ptr == '%')
{
my_ptr++;
if (*my_ptr == '%')
{
i += _putchar('%');
continue;
}
while (get_flag(*my_ptr, &flags))
my_ptr++;
mfunc = get_print(*my_ptr);
i += (mfunc)
? mfunc(arguments, &flags)
: _printf("%%%c", *my_ptr);
}
else
i += _putchar(*my_ptr);
}
_putchar(-1);
va_end(arguments);
return (i);
}
