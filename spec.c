#include "main.h"

/**
* get_spec - find the format fun
*
* @s: string
*
* Return: number of bytes
*/

int (*get_spec(char *s))(va_list a, params_t *params)
{
spec_t specs[] = {
{"c", print_char},
{"d", print_int},
{"%", print_percent},
{"i", print_int},
{"s", print_string},
{"b", print_binary},
{"o", print_octal},
{"u", print_unsigned},
{"x", print_hex},
{"X", print_HEX},
{"p", print_address},
{"S", print_S},
{"r", print_rev},
{"R", print_rot13},

{NULL, NULL}
};

int i = 0;

while (specs[i].spec)
{
if (*s == specs[i].spec[0])
{
return (specs[i].f);
}
i++;
}
return (NULL);
}

/**
* get_print_func - find the format fun
*
* @s: the format str
* @a: argument ptr
* @param: parammeters struct
*
* Return: number of bytes
*/

int get_print_func(char *s, va_list a, params_t *params)
{
int (*f)(va_list, params_t *) = get_spec(s);

if (f)
return (f(a, params));
return (0);
}

/**
* get_flag - finds the flag func
*
* @s: format srting
* @params: parameters struct
*
* Return: if flag valid
*/

int get_flag(char *s, params_t *params)
{
int i = 0;

switch (*s)
{
case '+':
i = params->plus = 1;
break;
case ' ':
i = params->space = 1;
break;
case '#':
i = params->hashtag = 1;
break;
case '-':
i = params->minus = 1;
break;
case '0':
i = params->zero = 1;
break;
}
return (i);
}

/**
* get_modifier - finds the modifier func
*
* @s: format tring
* @params: parameter struct
*
* Return: if modifier is valid
*/

int get_modifier(char *s, params_t *params)
{
int i = 0;

switch (*s)
{
case 'h':
i = params->h_modifier = 1;
break;
case 'l':
i = params->l_modifier = 1;
break;
}
return (i);
}

/**
* get_width - gets width from format str
*
* @s: format string
* @params: parameters struct
* @a: argument ptr
*
* Return: new ptr
*/

char *get_width(char *s, params_t *params, va_list a)
{
int d = 0;

if (*s == '*')
{
d = va_arg(a, int);
s++;
}
else
{
while (_isdigit(*s))
d = d * 10 + (*s++ - '0');
}
params->width = d;
return (s);
}
