#include "main.h"

/**
* init_param - clear struct and reset
*
* @param: parameters struct
* @a: argument ptr
*
* Return: void
*/

void init_param(param_t *param, va_list a)
{
param->unsign = 0;
param->space = 0;
param->hash = 0;
param->zero = 0;
param->plus = 0;
param->minus = 0;
param->h_modifier = 0;
param->l_modifier = 0;


(void)a;
}
