#include "ft_printf.h"

void clear_format(format_t *fmt) {

    fmt->is_zero_flag = 0;
    fmt->is_minus_flag = 0;
    fmt->width = 0;
    fmt->precision = -1;
    fmt->specifier = 0;
}

char *parse_loop(format_t *fmt, char *ptr, va_list ap) {

    while (!(strchr(TYPES, *ptr))){
        if ('1' <= *ptr && *ptr <= '9')
            fmt->width = myatoi(&ptr);
        else {
            if (*ptr == '.'){
                ptr++;
                if (*ptr == '*')
                    fmt->precision = va_arg(ap, int);
                else {
                    fmt->precision = myatoi(&ptr);
                    ptr--;
                }
            }
            else if (*ptr == '0')
                fmt->is_zero_flag = 1;
            else if (*ptr == '-')
                fmt->is_minus_flag = 1;
            else if (*ptr == '*')
                fmt->width = va_arg(ap, int);
            ptr++;
        }
    }
    return(ptr);
}

int	parse(format_t *fmt, const char **str, va_list ap) {

    char *ptr;

    (*str)++;
    clear_format(fmt);
    ptr = parse_loop(fmt, (char*) *str, ap);
    fmt->specifier = *ptr;
    if (fmt->width < 0)
        fmt->is_minus_flag = 1;
    if (fmt->precision >= 0)
        fmt->is_zero_flag = 0;
    if (fmt->is_minus_flag)
        fmt->is_zero_flag = 0;
    *str = ptr + 1;
    return (0);
}

// %[flags][  width  ][  precision  ][specifier]
// %[0 | -][width | *][precision | *][specifier]
