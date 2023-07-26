#include "main.h"

/**
* print_from_to - prints a rang of char addresses
*
* @start: starting address
* @stop: last address
* @except: except address
*
* Return: number bytes printed
*/

int print_from_to(char *start, char *stop, char *except)
{
int sum = 0;

while (start <= stop)
{
if (start != except)
sum += _putchar(*start);
start++;
}
return (sum);
}

/**
* print_rev - prints str in reverse
*
* @a: string
* @params: parameters
*
* Return: number of bytes
*/

int print_rev(va_list a, params_t *params)
{
int len, sum = 0;
char *str = va_arg(a, char *);
(void)params;
if (str)
{
for (len = 0; *str; str++)
len++;
str--;
for (; len > 0; len--, str--)
sum += _putchar(*str);
}
return (sum);
}

/**
* print_rot13 - prints string in rot13
*
* @a: string
* @params: parameters struct
*
* Return: number bytes printed
*/

int print_rot13(va_list a, params_t *params)
{
int i, index;
int count = 0;
char arr[] =
"NOPQRSTUVWXYZABCDEFGHIJKLM     nopqrstuvwxyzabcdefghijklm";
char *b = va_arg(a, char *);
(void)params;

i = 0;
index = 0;
while (b[i])
{
if ((b[i] >= 'A' && b[i] <= 'Z') || (b[i] >= 'a' && b[i] <= 'z'))
{
index = b[i] - 65;
count += _putchar(arr[index]);
}
else
count += _putchar(b[i]);
i++;
}
return (count);
}
