#include "main.h"

/**
* get_spec - find the format fun
*
* @s: string
*
* Return: number of bytes
*/

int (*get_spec(char *s))(va_list a, param_t *param)
{
spec_t specs[] = {
{"c", print_char},
{"d", print_int},
{"%", print_percent},
{"i", print_int},
{"s", print_string},
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

int get_print_func(char *s, va_list a, param_t *param)
{
int (*f)(va_list, param_t *) = get_spec(s);

if (f)
return (f(a, param));
return (0);
}
