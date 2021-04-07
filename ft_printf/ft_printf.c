#include "ft_printf.h"

void clear_format(format_t *fmt){
    fmt->is_zero_flag = 0;
    fmt->is_minus_flag = 0;
    fmt->width = 0;
    fmt->precision = -1;
    fmt->specifier = 0;
}

int ft_printf(const char *str, ...){
    va_list	ap;
    format_t	fmt;
    int		ret;

    va_start(ap, str);
    ret = 0;
    clear_format(&fmt);
    while (*str){
        if (*str == '%'){
            if (*(str + 1) == '%'){
                putchar('%');
                str += 2;
                ret++;
            }
            else if(parse(&fmt, &str, ap) < 0)
                return (-1);
            ret += evaluate(fmt, ap);
            clear_format(&fmt);
        }
        else {
            putchar(*str++);
            ret++;
        }
    }
    va_end(ap);
    return ret;
}
