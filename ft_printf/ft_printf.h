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

int		ft_printf(const char *str, ...);
int		parse(format_t *fmt, const char **str, va_list ap);
int		evaluate(format_t fmt, va_list ap);

int		format_c(format_t fmt, char val);
int		format_s(format_t fmt, char *val);
//int		format_p(format_t fmt, va_list ap);
int		format_d(format_t fmt, long int val);
//int		format_x(format_t fmt, va_list ap);
//int		format_X(format_t fmt, va_list ap);

void	print_format(format_t fmt);
char*	ltoa(long int num);
int   myatoi(char **str);
void  putstr(const char *str);

#endif
