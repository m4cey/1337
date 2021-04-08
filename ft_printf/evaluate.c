#include "ft_printf.h"

int format_percent() {
    putchar('%');
    return (1);
}

int evaluate(format_t fmt, va_list ap) {
    int ret;

    ret = 0;
    if (fmt.specifier == 'c')
        ret = format_c(fmt, va_arg(ap, int));
    if (fmt.specifier == 's')
        ret = format_s(fmt, va_arg(ap, char*));
    if (fmt.specifier == 'p')
        ret = format_p(fmt, va_arg(ap, void*));
    if (fmt.specifier == 'd' || fmt.specifier == 'i')
        ret = format_d(fmt, va_arg(ap, int));
    if (fmt.specifier == 'u')
        ret = format_d(fmt, va_arg(ap, unsigned int));
    if (fmt.specifier == 'x')
        ret = format_x(fmt, va_arg(ap, unsigned int), 'a', 0);
    if (fmt.specifier == 'X')
        ret = format_x(fmt, va_arg(ap, unsigned int), 'A', 0);
    if (fmt.specifier == '%')
        ret = format_percent();

    return (ret);
}
