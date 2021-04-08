#include "ft_printf.h"

int	format_c(format_t fmt, char val) {
    int		ret;

    ret = 1;
    if (fmt.is_minus_flag)
        putchar(val);
    if (fmt.width){
        while(ret < ABS(fmt.width)){
            putchar(' ');
            ret++;
        }
    }
    if (!fmt.is_minus_flag)
        putchar(val);
    return (ret);
}
