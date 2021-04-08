#include "ft_printf.h"

int ft_printf(const char *str, ...) {
    va_list	ap;
    format_t	fmt;
    int		ret;

    if (str == NULL)
        return (-1);
    va_start(ap, str);
    ret = 0;
    while (*str){
        if (*str == '%'){
            parse(&fmt, &str, ap);
            ret += evaluate(fmt, ap);
        }
        else {
            putchar(*str++);
            ret++;
        }
    }
    va_end(ap);
    return ret;
}
