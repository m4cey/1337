#include "ft_printf.h"

int	base_s(format_t fmt, char *val) {
    int i;

    i = 0;
    while (val[i] && (i < fmt.precision || fmt.precision < 0))
        putchar(val[i++]);
    return (i);
}

int	format_s(format_t fmt, va_list ap) {
    int ret;
    int len;
    char* val;

    val = va_arg(ap, char*);
    ret = 0;
    if (fmt.width < 0 || fmt.is_minus_flag) {
        ret += base_s(fmt, val);
        while(ret < ABS(fmt.width)){
            putchar(' ');
            ret++;
        }
    }
    else {
        len = 0;
        while (val[len] && (len < fmt.precision || fmt.precision < 0))
            len++;
        while(ret + len < ABS(fmt.width)){
            putchar(' ');
            ret++;
        }
        ret += base_s(fmt, val);
    }
    return (ret);
}
