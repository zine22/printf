#include "main.h"

/**
* _puts - print strings
*
* @str: string
*
* Return: void
*/

int _puts(char *str)
{
char *i = str;

while (*str)
_putchar(*str++);
return (str - i);
}

/**
* _putchar - writes c to stdout
*
* @c: character
*
* Return: 1 or -1
*/

int _putchar(int c)
{
static int j;
static char buf[OUTPUT_BUF_SIZE];

if (c == BUF_FLUSH || j >= OUTPUT_BUF_SIZE)
{
write(1, buf, j);
j = 0;
}
if (c != BUF_FLUSH)
buf[j++] = c;
return (1);
}
