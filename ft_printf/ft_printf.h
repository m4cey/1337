#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
// temporary {{
#include <string.h>
#include <stdio.h>
// }}
#define ABS(x) x * (-1 * (x < 0)) + x * (x >= 0)
#define TYPES "cspdiuxX"

typedef struct {
    int		is_zero_flag;
    int		is_minus_flag;
    int		width;
    int		is_var_width;
    int		precision;
    int		is_var_precision;
    char	specifier;
} format_t;
typedef int (*format_callback)(format_t fmt, va_list ap);

int		ft_printf(const char *str, ...);
void	print_format(format_t fmt);
char*	tostr(int num);
int		parse(format_t *fmt, const char **str, va_list ap);
int		evaluate(format_t fmt, va_list ap);
void  putstr(const char *str);

int		format_c(format_t fmt, va_list ap);
int		format_s(format_t fmt, va_list ap);
//int		format_p(format_t fmt, va_list ap);
int		format_d(format_t fmt, va_list ap);
/*
   int		format_i(format_t fmt, va_list ap);
   int		format_u(format_t fmt, va_list ap);
   int		format_x(format_t fmt, va_list ap);
   int		format_X(format_t fmt, va_list ap);
   */
int strfromd(char *restrict str, size_t n, const char *restrict format, float fp);

#endif
