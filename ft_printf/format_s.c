#include "ft_printf.h"

int	base_s(format_t fmt, char *val) {
    int i;

    i = 0;
    while (val && val[i] && (i < fmt.precision || fmt.precision < 0))
        putchar(val[i++]);
    return (i);
}

char *nullify(format_t *fmt, char *val) {

    if (val == NULL) {
        if (-1 < fmt->precision && fmt->precision < 6)
            fmt->precision = 0;
        val = strdup("(null)");
    }
    return (val);
}

int width_s(format_t fmt, int ret, int len) {

    while(ret + len < ABS(fmt.width)){
        putchar(' ');
        ret++;
    }
    return (ret);
}

int	format_s(format_t fmt, va_list ap) {
    int ret;
    int len;
    int null;
    char* val;

    if(!(val = va_arg(ap, char*)))
        null = 1;
    val = nullify(&fmt, val);
    ret = 0;
    if (fmt.is_minus_flag) {
        ret += base_s(fmt, val);
        ret += width_s(fmt, ret, 0);
    }
    else {
        len = 0;
        while (val && val[len] && (len < fmt.precision || fmt.precision < 0))
            len++;
        ret += width_s(fmt, ret, len);
        ret += base_s(fmt, val);
    }
    if (null)
        free(val);
    return (ret);
}
