#include "main.h"

/**
* _printf - prints anything
*
* @format: the format string
*
* Return: number of bytes
*/

int _printf(const char *format, ...)
{
int sum = 0;
va_list a;
char *p, *start;
param_t param = PARAM_INIT;

va_start(a, format);

if (!format || (format[0] == '%' && !format[1]))
return (-1);
if (format[0] == '%' && format[1] == ' ' && !format[2])
return (-1);
for (p = (char *)format; *p; p++)
{
init_param(&param, a);
if (*p != '%')
{
sum += _putchar(*p);
continue;
}
start = p;
p++;
while (get_flag(p, &param))
{
p++;
}
p = get_width(p, &param, a);
p = get_precision(p, &param, a);

if (get_modifier(p, &param))
p++;
if (!get_spec(p))
sum += print_from_to(start, p, param.l_modifier || param.h_modifier ? p - 1 : 0);
else
sum += get_print_func(p, a, &param);
}
_putchar(BUF_FLUSH);
va_end(a);

return (sum);
}
