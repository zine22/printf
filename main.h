#ifndef _PRINTF_H
#define _PRINTF_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"

#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE   1
#define CONVERT_UNSIGNED    2

/**
* struct parameters -parameters struct
*
* @unsign: flag if unsign value
* @plus: flag spec
* @space: flag spec
* @hashtag: flag
* @zero: flag
* @minus: flag
* @width: field width
* @precision: field precision
* @h_modifier: on if spec
* @l_modifier: on if spec
*/

typedef struct parameters
{
unsigned int unsign       : 1;
unsigned int plus         : 1;
unsigned int space        : 1;
unsigned int hashtag      : 1;
unsigned int zero         : 1;
unsigned int minus        : 1;
unsigned int width;
unsigned int precision;
unsigned int h_modifier   : 1;
unsigned int l_modifier   : 1;
} params_t;

/**
* struct spec - struct token
*
* @spec: format
* @f: the function
*/
typedef struct spec
{
char *spec;
int (*f)(va_list, params_t *);
} spec_t;


int print_percent(va_list a, params_t *params);
int print_string(va_list a, params_t *params);
int print_char(va_list a, params_t *params);

int print_int(va_list a, params_t *params);

int _puts(char *str);
int _putchar(int c);


int _printf(const char *format, ...);


#endif
