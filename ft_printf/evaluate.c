#include "ft_printf.h"

int evaluate(format_t fmt, va_list ap){
    format_callback format_list[strlen(TYPES)];
    int ret;
    int	i;

    ret = 0;
    i = 0;
    format_list[0] = format_c;
    format_list[1] = format_s;
    //format_list[2] = format_p;
    format_list[3] = format_d;
    /*
   format_list[4] = format_i;
   format_list[5] = format_u;
   format_list[6] = format_x;
   format_list[7] = format_X;
       */
    while (TYPES[i] != fmt.specifier)
        i++;
    ret = (format_list[i])(fmt, ap);
    return (ret);
}
