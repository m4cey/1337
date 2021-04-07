#include "ft_printf.h"

int base_d(format_t fmt, char *str, int val) {
    int i;

    i = strlen(str);
    if (val < 0 && !fmt.is_zero_flag)
        putchar('-');
    while (fmt.precision >= 0 && i < fmt.precision && i++)
        putchar('0');
    putstr(str);
    return (i);
}

int	format_d(format_t fmt, va_list ap) {
    int     ret;
    int     val;
    int     len;
    char*   str;

    val = va_arg(ap, int);
    str = tostr(val);
    ret = val < 0;
    if (fmt.is_minus_flag) {
        ret += base_d(fmt, str, val);
        while(ret < ABS(fmt.width)){
            putchar(' ');
            ret++;
        }
    }
    else {
        len = strlen(str);
        while (fmt.precision >= 0 && len < fmt.precision && len++);
        if (val < 0 && fmt.is_zero_flag)
            putchar('-');
        while(ret + len < ABS(fmt.width)){
            if (fmt.is_zero_flag && fmt.precision < 0)
                putchar('0');
            else
                putchar(' ');
            ret++;
        }
        ret += base_d(fmt, str, val);
    }
    free(str);
    return ret;
}
