#include "ft_printf.h"

int base_x(format_t fmt, char *str, long int val) {
    int i;

    i = strlen(str);
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

int width_x(format_t fmt, int ret, int len) {

    while(ret + len < ABS(fmt.width)){
        if (!fmt.is_minus_flag && fmt.is_zero_flag && fmt.precision < 0)
            putchar('0');
        else
            putchar(' ');
        ret++;
    }
    return (ret);
}

int format_x(format_t fmt, unsigned int val, int alpha_offset) {
    int     ret;
    int     len;
    char*   str;

    str = utoh(val, alpha_offset);
    ret = 0;
    if (fmt.is_minus_flag) {
        ret += base_x(fmt, str, val);
        ret = width_x(fmt, ret, 0);
    }
    else {
        len = strlen(str);
        while (fmt.precision >= 0 && len < fmt.precision && len++);
        ret += width_x(fmt, ret, len);
        ret = base_x(fmt, str, val);
    }
    free(str);
    return ret;
}
