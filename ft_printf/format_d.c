#include "ft_printf.h"

int base_d(format_t fmt, char *str, long int val) {
    int i;

    i = strlen(str);
    if (val < 0 && !fmt.is_zero_flag)
        putchar('-');
    while (fmt.precision >= 0 && i < fmt.precision && i++)
        putchar('0');
    if (fmt.precision == 0 && val == 0) {
        if (fmt.width > 0)
            putchar(' ');
    }
    else
        putstr(str);
    return (i);
}

int width_d(format_t fmt, int ret, int len) {

    while(ret + len < ABS(fmt.width)){
        if (!fmt.is_minus_flag && fmt.is_zero_flag && fmt.precision < 0)
            putchar('0');
        else
            putchar(' ');
        ret++;
    }
    return (ret);
}

int	format_d(format_t fmt, long int val) {
    int     ret;
    int     len;
    char*   str;

    str = ltoa(val);
    ret = val < 0;
    if (fmt.is_minus_flag) {
        ret += base_d(fmt, str, val);
        ret = width_d(fmt, ret, 0);
    }
    else {
        len = strlen(str);
        while (fmt.precision >= 0 && len < fmt.precision && len++);
        if (val < 0 && fmt.is_zero_flag)
            putchar('-');
        ret += width_d(fmt, ret, len);
        ret = base_d(fmt, str, val);
    }
    free(str);
    return ret;
}
