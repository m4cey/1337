#include "ft_printf.h"

int	format_c(format_t fmt, va_list ap){
    char	c;
    int		ret;

    if (fmt.is_var_width)
        fmt.width = va_arg(ap, int);
    c = (char)va_arg(ap, int);
    ret = 1;
    if (fmt.width < 0 || fmt.is_minus_flag)
        putchar(c);
    if (fmt.width){
        while(ret < ABS(fmt.width)){
            putchar(' ');
            ret++;
        }
    }
    if (fmt.width >= 0 && !fmt.is_minus_flag)
        putchar(c);
    return (ret);
}
