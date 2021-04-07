#include "ft_printf.h"

int	base_s(format_t fmt, char *val) {
    int i;

    i = 0;
    while (val && val[i] && (i < fmt.precision || fmt.precision < 0))
        putchar(val[i++]);
    return (i);
}

int	format_s(format_t fmt, va_list ap) {
    int ret;
    int len;
    int null;
    char* val;

    val = va_arg(ap, char*);
    ret = 0;
    if (!val) {
        null = 1;
        if (-1 < fmt.precision && fmt.precision < 6)
            fmt.precision = 0;
        val = strdup("(null)");
    }
    if (fmt.is_minus_flag) {
        ret += base_s(fmt, val);
        while(ret < ABS(fmt.width)){
            putchar(' ');
            ret++;
        }
    }
    else {
        len = 0;
        while (val && val[len] && (len < fmt.precision || fmt.precision < 0))
            len++;
        while(ret + len < ABS(fmt.width)){
            putchar(' ');
            ret++;
        }
        ret += base_s(fmt, val);
    }
    if (null)
        free(val);
    return (ret);
}
