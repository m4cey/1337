#include "ft_printf.h"

int format_percent() {
    putchar('%');
    return (2);
}

int evaluate(format_t fmt, va_list ap) {
    int ret;

    ret = 0;
    if (fmt.specifier == 'c')
        ret = format_c(fmt, va_arg(ap, int));
    if (fmt.specifier == 's')
        ret = format_s(fmt, va_arg(ap, char*));
    if (fmt.specifier == 'd' || fmt.specifier == 'i')
        ret = format_d(fmt, va_arg(ap, int));
    if (fmt.specifier == 'u')
        ret = format_d(fmt, va_arg(ap, unsigned int));
    if (fmt.specifier == '%')
        ret = format_percent();
    return (ret);
}
