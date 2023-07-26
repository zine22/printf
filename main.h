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
int print_S(va_list a, params_t *params);
int print_int(va_list a, params_t *params);

char *convert(long int num, int base, int flags, params_t *params);
int print_unsigned(va_list a, params_t *params);
int print_address(va_list a, params_t *params);


int (*get_spec(char *s))(va_list a, params_t *params);
int get_print_func(char *s, va_list a, params_t *params);
int get_flag(char *s, params_t *params);
int get_modifier(char *s, params_t *params);
char *get_width(char *s, params_t *params, va_list a);


int print_hex(va_list a, params_t *params);
int print_HEX(va_list a, params_t *params);
int print_binary(va_list a, params_t *params);
int print_octal(va_list a, params_t *params);


int print_from_to(char *start, char *stop, char *except);
int print_rev(va_list a, params_t *params);
int print_rot13(va_list a, params_t *params);


int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);


void init_params(params_t *params, va_list a);

char *get_precision(char *p, params_t *params, va_list a);

int _puts(char *str);
int _putchar(int c);


int _printf(const char *format, ...);


#endif
