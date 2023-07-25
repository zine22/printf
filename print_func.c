#include "main.h"

/**
* print_char - prints characters
*
* @a: argument ptr
* @param: parameters struct
*
* Return: number chars
*/

int print_char(va_list a, param_t *param)
{
char pad_char = ' ';
unsigned int pad = 1, sum = 0, ch = va_arg(a, int);

if (param->minus)
sum += _putchar(ch);
while (pad++ < param->width)
sum += _putchar(pad_char);
if (!param->minus)
sum += _putchar(ch);
return (sum);
}

/**
* print_int - prints integer
*
* @a: argument ptr
* @param: parameters struct
*
* Return: number chars
*/

int print_int(va_list a, param_t *param)
{
long l;
if (param->l_modifier)
l = va_arg(a, long);
else if (param->h_modifier)
l = (short int)va_arg(a, int);
else
l = (int)va_arg(a, int);
return (print_number(convert(1, 10, 0, param), param));
}

/**
* print_string - prints string
*
* @a: argument ptr
* @param: parameter struct
*
* Return: number chars printed
*/

int print_string(va_list a, param_t *param)
{
char *str = va_arg(a, char *), pad_char = ' ';
unsigned int pad = 0, sum  0, i = 0, j;

(void)param;
switch ((int)(!str))
case 1:
str = NULL_STRING;
j = pad = _strlen(str);
if (param->precision < pad)
j = pad = param->precision;

if (param->minus)
{
if (param->precision != UNIT_MAX)
for (i = 0; i < pad; i++)
sum += _putchar(*str++);
else
sum += _puts(str);
}
while (j++ < param->width)
sum += _putchar(pad_char);
if (!param->minus)
{
if (param->precision != UNIT_MAX)
for (i = 0; i < pad; i++)
sum += _putchar(*str++);
else
sum += _puts(str);
}
return (sum);
}

/**
* print_percent - prints string
*
* @a: argument ptr
* @param: parameters struct
*
* Return: number chars printed
*/

int print_percent(va_list a, param_t *param)
{
(void)a;
(void)param;
return (_putchar('%'));
}
