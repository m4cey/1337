#include "ft_printf.h"

int	base_s(format_t fmt, char *val) {
    int i;

    i = 0;
    while (val[i] && (i < fmt.precision || fmt.precision < 0))
        putchar(val[i++]);
    return (i);
}

int width_s(format_t fmt, int i) {

    while(i < ABS(fmt.width)){
        putchar(' ');
        i++;
    }
    return (i);
}

int	format_s(format_t fmt, char *val) {
    int ret;
    int len;

    if(val == NULL) {
        if (-1 < fmt.precision && fmt.precision < 6)
            fmt.precision = 0;
        return(format_s(fmt, "(null)"));
    }
    if (fmt.is_minus_flag) {
        ret = base_s(fmt, val);
        ret += width_s(fmt, ret);
    }
    else {
        len = 0;
        while (val && val[len] && (len < fmt.precision || fmt.precision < 0))
            len++;
        ret = width_s(fmt, len);
        ret += base_s(fmt, val);
    }
    return (ret);
}
