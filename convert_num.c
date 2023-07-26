#include "main.h"

/**
* print_hex - prints hex numbers lowercase
*
* @a: argument ptr
* @params: parameters struct
*
* Return: bytes printed
*/

int print_hex(va_list a, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(a, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(a, unsigned int);
else
l = (unsigned int)va_arg(a, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag && l)
{
*--str = 'x';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
* print_HEX - print hex in uppercase
*
* @a: argument ptr
* @params: parameters struct
*
* Return: bytes printed
*/

int print_HEX(va_list a, params_t *params)
{
unsigned long l;
int c = 0;
char *str;

if (params->l_modifier)
l = (unsigned long)va_arg(a, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(a, unsigned int);
else
l = (unsigned int)va_arg(a, unsigned int);

str = convert(l, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
if (params->hashtag && l)
{
*--str = 'X';
*--str = '0';
}
params->unsign = 1;
return (c += print_number(str, params));
}

/**
* print_binary - prints binary number
*
* @a: argument ptr
* @params: marameters struct
*
* Return: bytes printed
*/

int print_binary(va_list a, params_t *params)
{
unsigned int n = va_arg(a, unsigned int);
char *str = convert(n, 2, CONVERT_UNSIGNED, params);
int c = 0;

if (params->hashtag && n)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}

/**
* print_octal - prints octal numbers
*
* @a: argument ptr
* @params: parameters struct
*
* Return: bytes printed
*/

int print_octal(va_list a, params_t *params)
{
unsigned long l;
char *str;
int c = 0;

if (params->l_modifier)
l = (unsigned long)va_arg(a, unsigned long);
else if (params->h_modifier)
l = (unsigned short int)va_arg(a, unsigned int);
else
l = (unsigned int)va_arg(a, unsigned int);
str = convert(l, 8, CONVERT_UNSIGNED, params);

if (params->hashtag && l)
*--str = '0';
params->unsign = 1;
return (c += print_number(str, params));
}
