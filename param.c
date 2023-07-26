#include "main.h"

/**
* init_params - clear struct and reset
*
* @params: parameters struct
* @a: argument ptr
*
* Return: void
*/

void init_params(params_t *params, va_list a)
{
params->unsign = 0;
params->space = 0;
params->hashtag = 0;
params->zero = 0;
params->plus = 0;
params->minus = 0;
params->h_modifier = 0;
params->l_modifier = 0;
params->width = 0;
params->precision = UINT_MAX;


(void)a;
}
